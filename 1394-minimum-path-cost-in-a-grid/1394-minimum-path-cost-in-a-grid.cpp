// class Solution {
// private:
//     int dpcheck(int i, int j, int n, int m, vector<vector<int>>& dp,vector<vector<int>>& grid, vector<vector<int>>& cost){
//         if(i == n-1) return grid[n-1][j];
//         if(dp[i][j] != -1) return dp[i][j];

//         int count1 = INT_MAX; int count2 =  INT_MAX; int count3 = INT_MAX;
//         int k = grid[i][j];
//         if(i < n-1){
//             count1 = grid[i][j] + cost[k][j] + dpcheck(i+1,j,n,m,dp,grid,cost);
//         }
//         if(i < n-1 && j < m-1){
//             count2 = grid[i][j] + cost[k][j+1] + dpcheck(i+1,j+1,n,m,dp,grid,cost);
//         }
//         if(i < n-1 && j > 0){
//             count3 = grid[i][j] + cost[k][j-1] + dpcheck(i+1,j-1,n,m,dp,grid,cost);
//         }
//         return dp[i][j] = min(count1,min(count2,count3));
//     }
// public:
//     int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//         int n = grid.size(); int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int> (m,-1));
//         int ans = INT_MAX;
//         for(int i=0; i<m; i++){
//             ans = min(ans,dpcheck(0,i,n,m,dp,grid,moveCost));
//         }
//         return ans;
//     }
// };


class Solution {
private:
    int dpcheck(int i, int j, int n, int m, vector<vector<int>>& dp, vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        if (i == n - 1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        
        int min_cost = INT_MAX;
        int current_val = grid[i][j];
        
        // Consider all possible columns in the next row
        for (int j_next = 0; j_next < m; ++j_next) {
            int cost = current_val + moveCost[current_val][j_next] + dpcheck(i + 1, j_next, n, m, dp, grid, moveCost);
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        
        return dp[i][j] = min_cost;
    }

public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int ans = INT_MAX;
        for (int j = 0; j < m; ++j) {
            ans = min(ans, dpcheck(0, j, n, m, dp, grid, moveCost));
        }
        return ans;
    }
};