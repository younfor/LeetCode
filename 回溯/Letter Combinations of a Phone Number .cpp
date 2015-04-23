/*Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.*/

class Solution {
public:
    void back(string num[], string s, int index, string ans, vector<string> &v)
    {
    	if (index == s.length())
    	{
    		v.push_back(ans);
    	}
    	else
    	{
    		//for (int i = index; i<s.length(); i++)
    		//{
    		int i = index;
    			int loc = s[i] - '0';
    			char c = ans[i];
    			for (int j = 0; num[loc][j] != '\0'; j++)
    			{
    				ans[i] = num[loc][j];
    				back(num, s, i + 1, ans, v);
    			}
    			ans[i] = c;
    		//}
    	}
    
    }
    vector<string> letterCombinations(string digits) {
    	string num[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    	vector<string> v;
    	if (digits.length() == 0) return v;
    	string ans = digits;
    	back(num, digits, 0, ans, v);
    	return v;
    
    }
};