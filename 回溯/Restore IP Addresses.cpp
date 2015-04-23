/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)*/
class Solution {
public:
    void judge(vector<string> &v, string s, vector<int> &visit)
    {
    	string str, max = "255";
    	bool zerobegin=false;
    	int j = 0,zero=0,point=0;
    	for (int i = 0; i<s.length(); i++)
    	{
    		str += s[i];
    		j++;
    		if (j>3 ||(j==2&&s[i-1]=='0')||(j==3&&s[i-2]=='0')|| (j == 3 && (s.substr(i - 2, 3)>max)) || visit[i] <0)
    			return;
    		if (visit[i] == 1)
    		{
    			str += '.';
    			j = 0;
    			point++;
    		}
    	}
    	if(point==3)
    	    v.push_back(str);
    }
    void dfs(vector<string> &v, string s, vector<int> &visit, int index,int count)
    {
    	judge(v, s, visit);
    	if (visit[index]<0)
    	{
    		visit[index] = 0;
    		dfs(v, s, visit, index + 1,count);
    		visit[index] = 1;
    		if (count<3)
    			dfs(v, s, visit, index + 1,count+1);
    		visit[index] = -1;
    	}
    }
    vector<string> restoreIpAddresses(string s) {
    	vector<string> v;
    	if (s.length()<1||s.length()>12) return v;
    	vector<int> visit(s.length(), -1);
    	visit[s.length() - 1] = 999;
    	dfs(v, s, visit, 0,0);
    	return v;
    }
};