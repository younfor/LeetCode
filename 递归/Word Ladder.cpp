/*Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.*/

class Solution {
public:

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<string> q;
        q.push(beginWord);
        wordDict.insert(endWord);
        int count=1;
        while(!q.empty())
        {
            int len=q.size();
            
            for(int i=0;i<len;i++)
            {
                string s=q.front();
                q.pop();
                if(s==endWord)
                    return count;
                //找匹配
                int slen=s.length();
                for(int j=0;j<slen;j++)
                {
                    //之所以不用循环遍历wordDict匹配是因为len(wordDict)很可能 > slen*26
                    for(char c='a';c<='z';c++)
                    {
                        char back=s[j];
                        s[j]=c;
                        if(wordDict.find(s)!=wordDict.end())
                        {
                            q.push(s);
                            wordDict.erase(s);
                        }
                        s[j]=back;
                    }
                }
            }
            count++;
            
        }
        return 0;
    }
};