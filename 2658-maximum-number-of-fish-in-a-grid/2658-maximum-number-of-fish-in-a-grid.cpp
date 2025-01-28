class Solution {
private:
    void dfscheck(int row, int col,int n, int m,vector<int> &delrow, vector<int> &delcol,
    vector<vector<int>> &vis,vector<vector<int>> &grid,int& sum){
        vis[row][col] = 1;
        sum += grid[row][col];
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] != 0 && vis[nrow][ncol] == 0){
                dfscheck(nrow,ncol,n,m,delrow,delcol,vis,grid,sum);
            }
        }
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n =  grid.size(); int m = grid[0].size();
        vector<vector<int>> vis (n,vector<int> (m,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0 && vis[i][j] == 0){
                    int sum = 0;
                    dfscheck(i,j,n,m,delrow,delcol,vis,grid,sum);
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};

