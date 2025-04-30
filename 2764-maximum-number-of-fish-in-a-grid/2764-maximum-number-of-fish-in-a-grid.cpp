class Solution {
private:
    void dfscheck(int& count,int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col] = 1;
        count += grid[row][col];
        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] != 0){
    
                dfscheck(count,nrow,ncol,n,m,vis,grid);
            }
        }
    }
public:
    int findMaxFish(vector<vector<int>>& board) {
        int n = board.size(); int m  = board[0].size();
        vector<vector<int>> vis(n , vector<int> (m,0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 0;
                if(!vis[i][j] && board[i][j] != 0){
                    dfscheck(count,i,j,n,m,vis,board);
                    ans = max(ans,count);
                    count = 0;
                }
            }
        }
        return ans;
    }
};