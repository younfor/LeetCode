/*Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Show Tags
*/



class Solution {
public:
    struct node{
	int x, y;
	node(int a, int b){ x = a; y = b; }
};
void bfs(int i, int j, int row, int col, vector<bool> &visit, vector<vector<char>> &board,queue<struct node> &q)
{
	int d[] = { -1, 0, 0, -1, 1, 0, 0, 1 };
	for (int m = 0; m<4; m ++)
	{
		int _x = i + d[2*m], _y = j + d[2*m+1];
		if (_x >= row || _y >= col ||_x<0 ||_y<0)
			continue;
		if (!visit[_x*row + _y]&&board[_x][_y]=='O')
		{
			q.push(node(_x,_y));
		}	
	}
}
void solve(vector<vector<char>> &board) {
	int row = board.size();
	if (row == 0) return;
	int col = board[0].size();
	vector<bool> visit(row*col, false);
	queue<struct node> q;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			if ((i==0||j==0||i==row-1||j==col-1)&&board[i][j]=='O')
			{
				q.push(node(i, j));
			}
		}
	}
	while (!q.empty())
	{
		struct node node = q.front();
		q.pop();
		if (!visit[node.x*row + node.y] && board[node.x][node.y] == 'O')
		{
			visit[node.x*row + node.y] = true;
			bfs(node.x, node.y, row, col, visit,board,q );
		}
	}
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			if (visit[i*row+j]==false&&board[i][j]=='O')
			{
				board[i][j] = 'X';
			}
		}
	}
}
};