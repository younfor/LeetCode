/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]*/

class Solution {
public:
    bool judge(string s)
{
	int i = 0, j = s.length() - 1;
	while (i <= j &&s[i] == s[j])
	{
		i++;
		j--;
	}
	if (i>j)
		return true;
	else
		return false;
}

void dfs(string &s, int l, vector<vector<string> > &v, vector<string> &temp)
{
	
	if (l == s.length())
	{
		v.push_back(vector<string>(temp));
	}
	else
	{
		for (int j = l; j < s.length(); j++)
		{
			string str = s.substr(l, j - l + 1);
			if (judge(str))
			{
				temp.push_back(str);
				dfs(s, j+1, v, temp);
				temp.pop_back();
			}
				
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string> > v;
	vector<string> temp;
	dfs(s, 0, v, temp);
	return v;
}
};