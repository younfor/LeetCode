/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
	//层次遍历,用队列
	vector<vector<int> > vv;
	if (root == NULL) return vv;
	queue<TreeNode*> q;
	TreeNode * level=root,*temp;
	q.push(root);
	vector<int> v;
	while (!q.empty())
	{
		TreeNode *t=q.front();
		q.pop();
		v.push_back(t->val);
		if (t->left)
		{
			q.push(t->left);
			temp = t->left;
		}
		if (t->right)
		{
			q.push(t->right);
			temp = t->right;
		}
		if (t == level)
		{
			level = temp;
			vv.push_back(v);
			v.clear();
		}	
	}
	return vv;
}
};