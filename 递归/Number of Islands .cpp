/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.*/


class Solution {
public:
    

void dfs(vector<vector<char> > &grid,int i, int j,int row,int col)
{
	
	grid[i][j] = '0';
	//cout << i << ":" << j << endl;
	int flag[] = { -1, 0, 0, -1, 1, 0, 0, 1 };
	for (int ch = 0; ch < 4; ch++)
	{
		int l = i + flag[2 * ch];
		int r = j + flag[2 * ch + 1];
		if (l >= 0 && l< row && r >= 0 && r< col && grid[l][r] == '1' )
		{
			dfs(grid, l, r, row, col);
		}
	}
}
int numIslands(vector<vector<char> > &grid) 
{
	int row = grid.size();
	if(row==0) return 0;
	int col = grid[0].size();
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			if ( grid[i][j] == '1')
			{
				count++;
				dfs(grid, i, j,row,col);
			}
				
		}
	}
	return count;
}
};