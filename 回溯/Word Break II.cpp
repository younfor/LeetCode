/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
class Solution {
public:
    // Word Break I
    bool isWordBreakable(string s, unordered_set<string> &dict) {
        int n = s.size();
        // f[i]: is first i letters s[0..i-1] consisted of words
        bool f[n + 1] = {false};

        f[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                // s[0..i-1] is breakable iff s[0..j-1] is and s[j..i-1] is a word for any j
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    f[i] = true;
                    break;
                }

        return f[n];
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        
    if (!isWordBreakable(s, dict))   return vector<string>();
	stack<int> stack;
	vector<int> visit(s.length(), -1);
	vector<string> result;
	stack.push(-1);
	while (!stack.empty())
	{
		int l = stack.top();
		stack.pop();
		l++;
		for (int j = l; j < s.length(); j++)
		{
			if (dict.find(s.substr(l, j - l + 1)) != dict.end())
			{
				visit[j] = l-1;
				if (j == s.length() - 1)
				{
					int back = j;
					string temp;
					while (visit[back] != -1)
					{
						temp = s.substr(visit[back] + 1, back - visit[back])+" "+temp;
						back = visit[back];
					} 
					temp = s.substr(visit[back] + 1, back - visit[back])+" "+temp;
					temp = temp.substr(0, temp.length() - 1);
					result.push_back(temp);
				}
				stack.push(j);
			}
		}
	}
	return result;
}
};