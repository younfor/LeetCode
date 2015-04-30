/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.*/


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
    void dfs(TreeNode *t, int level, vector<vector<int> > &vv)
    {
    	if (t)
    	{
    		
    		//cout << "size:" << vv.size() << " level:" << level << endl;
    		if (vv.size() < level+1)
    		{
    			vector<int> v;
    			v.push_back(t->val);
    			vv.push_back(v);
    		}
    		else
    		{
    			vv[level].push_back(t->val);
    		}
    		dfs(t->left, level + 1,vv);
    		dfs(t->right, level + 1,vv);
    	}
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	vector<vector<int> > v;
    	dfs(root, 0, v);
    	reverse(v.begin(), v.end());
    	return v;
    }
};