/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode *t,int level,set<int> &s,vector<int> &v)
    {
        if(t)
        {
            if(s.find(level)==s.end())
            {
                v.push_back(t->val);
                s.insert(level);
            }
            dfs(t->right,level+1,s,v);
            dfs(t->left,level+1,s,v);
            
        }
    }
    vector<int> rightSideView(TreeNode *root) {
        set<int> s;
        vector<int> v;
        dfs(root,0,s,v);
        return v;
    }
};