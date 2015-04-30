/*Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.*/

class Solution {
public:
    void savepath(string begin,vector<vector<string>> &ans,vector<string> &path,map<string, vector<string>> &pathfather,string s)
    {
    	if (s == begin)
    	{
    		vector<string> newpath(path);
    		reverse(newpath.begin(), newpath.end());
    		ans.push_back(newpath);
    		return;
    	}
    	for (int i = 0; i < pathfather[s].size();i++)
    	{
    		path.push_back(pathfather[s][i]);
    		savepath(begin,ans, path, pathfather, pathfather[s][i]);
    		path.pop_back();
    	}
    }
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	//最终字符串序列组
	vector<vector<string>> ans;
	//存储路径-父节点(可能不止一个)
	map<string, vector<string>> pathfather;
	//用于BFS的队列
	queue<string> q;
	q.push(start);
	dict.insert(end);
	//存储层次使用过的
	set<string> tempused;
	bool find = true;
	while (!q.empty()&&find)
	{
		int len = q.size();
		tempused.clear();
		//层次遍历元素
		
		for (int i = 0; i<len; i++)
		{
			string s = q.front(),father=s;
			//cout << "队列:" << s << endl;
			q.pop();
			//找下一层的
			int slen = s.length();
			bool next = true;
			for (int j = 0; j<slen&&next; j++)
			{
				for (char c = 'a'; c <= 'z'; c++)
				{
					char back = s[j];
					s[j] = c;
					//如果存在加入路径
					if (dict.find(s) != dict.end())
					{
						//cout << "存在:" << s << endl;
						if (pathfather.find(s) == pathfather.end())
							pathfather[s] = vector<string>();
						pathfather[s].push_back(father);
						//如果是最后一个
						if (s == end)
						{
							//cout << "find" << endl;
							find = false;
							next = false;
							break;
						}else if(tempused.find(s) == tempused.end())
						{
							q.push(s);
							tempused.insert(s);
						}
					}
					s[j] = back;
				}
			}
		}
		for (set<string>::iterator it = tempused.begin(); it != tempused.end(); it++)
		{
			dict.erase(*it);
			//cout << "删除:" << *it << endl;
		}
			

	}
	vector<string> newpath;
	newpath.push_back(end);
	//cout << pathfather.size() << endl;
	savepath(start, ans, newpath, pathfather, end);
	//cout << ans.size();
	return ans;
}
};