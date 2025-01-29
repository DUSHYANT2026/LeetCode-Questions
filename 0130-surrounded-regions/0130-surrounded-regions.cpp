class Solution {
private:
    void dfscheck(int row,int col, int n, int m,vector<vector<int>> &vis,vector<vector<char>> & grid){
        vis[row][col] = 1;

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '0'){
                dfscheck(nrow,ncol,n,m,vis,grid);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(); int m = board[0].size();
        if(n == 0) return ;
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O' && (i == 0 || j == 0 || i == n-1 || j == m-1)){
                    dfscheck(i,j,n,m,vis,board);
                }
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                     dfscheck(i,j,n,m,vis,board);
                }
            }
        }
    }
};