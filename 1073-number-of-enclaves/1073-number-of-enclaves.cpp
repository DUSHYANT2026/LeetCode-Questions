class Solution {
private:
    void dfscheck(int row, int col, int n, int m,int& count, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col] = 1;
        grid[row][col] = 0;
        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                // grid[nrow][ncol] = 0;
                dfscheck(nrow,ncol,n,m,count,vis,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 1 && grid[i][j] == 1 &&  (i == 0 || i == n-1 || j == 0 || j == m-1)){
                    dfscheck(i,j,n,m,count,vis,grid);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};