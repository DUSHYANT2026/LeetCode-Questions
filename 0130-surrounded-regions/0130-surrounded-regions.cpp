class Solution {
private:
    void dfscheck(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &board) {
        vis[row][col] = 1;
        
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfscheck(nrow, ncol, n, m, vis, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) dfscheck(i, 0, n, m, vis, board);
            if (board[i][m-1] == 'O' && !vis[i][m-1]) dfscheck(i, m-1, n, m, vis, board);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) dfscheck(0, j, n, m, vis, board);
            if (board[n-1][j] == 'O' && !vis[n-1][j]) dfscheck(n-1, j, n, m, vis, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
