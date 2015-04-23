/*The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]*/
class Solution {
public:
    void dfs(vector<bool>& visit, vector<bool>& xvisit, vector<bool>& yvisit, int level, int n, vector<string> &v, vector<vector<string> > &result)
{
	if (level == n)
	{
		result.push_back(v);
	}
	else
	{
		for (int i = 0; i<n; i++)
		{
			if (!visit[i] && !xvisit[level + i] && !yvisit[level - i+n-1])
			{
				visit[i] = true;
				xvisit[level + i] = true;
				yvisit[level - i + n - 1] = true;
				v[level][i] = 'Q';
				dfs(visit, xvisit,yvisit, level + 1, n, v,result);
				visit[i] = false;
				xvisit[level + i] = false;
				yvisit[level - i + n - 1] = false;
				v[level][i] = '.';
			}
		}
	}

}
vector<vector<string> > solveNQueens(int n) {
	int c = 0;
	vector<bool> visit(n, false), xvisit(2 * n, false),yvisit(2*n,false);
	vector<string> v(n,string(n,'.'));
	vector<vector<string> > result;
	dfs(visit, xvisit,yvisit, 0, n,v,result);
	return result;

}
};