class Solution {
private:
    void dfscheck(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
    
        vector<pair<int,int>> nums = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0; i<4; i++){
            int nrow = row + nums[i].first;
            int ncol = col + nums[i].second;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && !grid[nrow][ncol]){
                dfscheck(nrow,ncol,n,m,grid,vis);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(); int m =  grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && !grid[i][j] && (i == 0 || j == 0 || i == n-1 || j == m-1)){
                    dfscheck(i,j,n,m,grid,vis);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && !grid[i][j]){
                    dfscheck(i,j,n,m,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};