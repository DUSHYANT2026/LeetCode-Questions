class Solution {
private:
    int dpsolve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        int left = 0; int right = 0;
        if(j > 0 && grid[i][j] != 1){
            left = dpsolve(i,j-1,dp,grid);
        }
        if(i > 0 && grid[i][j] != 1){
            right = dpsolve(i-1,j,dp,grid);
        }
        return dp[i][j] = (left + right);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(); int m  = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1]) return 0;
        vector<vector<int>> dp(n , vector<int> (m,-1));
        return dpsolve(n-1,m-1,dp,grid);
    }
};