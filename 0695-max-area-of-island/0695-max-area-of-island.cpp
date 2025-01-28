class Solution {
private:
    void dfscheck(int row, int col, int n, int m,  vector<vector<int>> &vis, vector<vector<int>>&grid,
    int &sum ){
        vis[row][col] = 1;
        sum++;
        vector<pair<int,int>> del = {{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0; i<4; i++){
            int nrow = row + del[i].first;
            int ncol = col + del[i].second;

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol]!=0 && vis[nrow][ncol] == 0){
                dfscheck(nrow,ncol,n,m,vis,grid,sum);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n =  grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0 && vis[i][j] == 0){
                    int sum = 0;
                    dfscheck(i,j,n,m,vis,grid,sum);
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};