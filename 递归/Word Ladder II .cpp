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
	//�����ַ���������
	vector<vector<string>> ans;
	//�洢·��-���ڵ�(���ܲ�ֹһ��)
	map<string, vector<string>> pathfather;
	//����BFS�Ķ���
	queue<string> q;
	q.push(start);
	dict.insert(end);
	//�洢���ʹ�ù���
	set<string> tempused;
	bool find = true;
	while (!q.empty()&&find)
	{
		int len = q.size();
		tempused.clear();
		//��α���Ԫ��
		
		for (int i = 0; i<len; i++)
		{
			string s = q.front(),father=s;
			//cout << "����:" << s << endl;
			q.pop();
			//����һ���
			int slen = s.length();
			bool next = true;
			for (int j = 0; j<slen&&next; j++)
			{
				for (char c = 'a'; c <= 'z'; c++)
				{
					char back = s[j];
					s[j] = c;
					//������ڼ���·��
					if (dict.find(s) != dict.end())
					{
						//cout << "����:" << s << endl;
						if (pathfather.find(s) == pathfather.end())
							pathfather[s] = vector<string>();
						pathfather[s].push_back(father);
						//��������һ��
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
			//cout << "ɾ��:" << *it << endl;
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