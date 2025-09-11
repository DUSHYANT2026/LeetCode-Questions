class Solution {
private:
    void dfscheck(int row, int col, int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid, int& sum) {
        vis[row][col] = 1;
        sum++;
        vector<pair<int,int>> nums = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for(int i = 0; i < 4; i++) {
            int nrow = nums[i].first + row;
            int ncol = nums[i].second + col;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && 
               vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfscheck(nrow, ncol, n, m, vis, grid, sum);
            }
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();  int m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1;
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    int sum = 0;
                    dfscheck(i, j, n, m, vis, grid, sum);
                    ans = max(ans, sum);
                    grid[i][j] = 0;
                }
            }
        }
        if(ans == 0) {
            vector<vector<int>> vis(n, vector<int>(m, 0));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1 && vis[i][j] == 0) {
                        int sum = 0;
                        dfscheck(i, j, n, m, vis, grid, sum);
                        ans = max(ans, sum);
                    }
                }
            }
        }
        
        return ans;
    }
};