/*Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
public:
    void dfs(vector<bool>& visit, vector<bool>& xvisit, vector<bool>& yvisit, int level, int n, int &c)
    {
    	if (level == n)
    	{
    		c++;
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
    				dfs(visit, xvisit,yvisit, level + 1, n, c);
    				visit[i] = false;
    				xvisit[level + i] = false;
    				yvisit[level - i + n - 1] = false;
    			}
    		}
    	}
    
    }
    int totalNQueens(int n) {
    	int c = 0;
    	vector<bool> visit(n, false), xvisit(2 * n, false),yvisit(2*n,false);
    	dfs(visit, xvisit,yvisit, 0, n, c);
    	return c;
    
    }
};