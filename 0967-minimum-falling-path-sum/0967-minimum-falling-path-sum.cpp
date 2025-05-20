// class Solution {
// private:
//     int dpcheck(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &grid){
//         if(i == n-1) return grid[n-1][j];

//         if(dp[i][j] != -1) return dp[i][j];
//         int count1 = INT_MAX; int count2 = INT_MAX; int  count3 = INT_MAX;
//         if(i < n-1){
//             count1 = grid[i][j] + dpcheck(i+1,j,n,m,dp,grid);
//         }
//         if(i < n-1 && j < m-1){
//             count2 = grid[i][j] + dpcheck(i+1,j+1,n,m,dp,grid);
//         }
//         if(i < n-1 && j > 0){
//             count3 = grid[i][j] + dpcheck(i+1,j-1,n,m,dp,grid);
//         }
//         return dp[i][j] = min(count1,min(count2,count3));
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size(); int m = grid[0].size();
//         vector<vector<int>> dp (n, vector<int> (m ,-1));
//         int ans = INT_MAX;
//         for(int i=0; i<m; i++){
//             ans = min(ans,dpcheck(0,i,n,m,dp,grid));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            dp[n-1][j] = grid[n-1][j];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                int down = dp[i+1][j];
                int downLeft = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int downRight = (j < m-1) ? dp[i+1][j+1] : INT_MAX;

                dp[i][j] = grid[i][j] + min({down, downLeft, downRight});
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < m; ++j) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};
