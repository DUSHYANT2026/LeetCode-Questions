// class Solution {
// public:
//     int dpcheck(int i, int j, int k, vector<vector<int>>&grid, vector<vector<vector<int>>> &dp){
//         if((i < 0 || j < 0 ) && k < 0){
//             return INT_MIN;
//         }
//         if(dp[i][j][k] != -1) return dp[i][j][k];

//         int count1 = 0; int count2 = 0; 
//         if(k > 0 && i > 0){
//             if(grid[i][j] == 1 && k > 0){
//                count1 += (1 + dpcheck(i-1,j,k-1,grid,dp)); 
//             }else if(grid[i][j] == 2 && k > 0){
//                 count1 += (2 + dpcheck(i-1,j,k-1,grid,dp));
//             }else{
//                 count1 = dpcheck(i-1,j,k,grid,dp); 
//             }
//         }
//         if(k > 0 && j > 0){
//             if(grid[i][j] == 1 && k > 0){
//                 count2 += (1 + dpcheck(i,j-1,k-1,grid,dp)); 
//             }else if(grid[i][j]  == 2 && k > 0){
//                 count2 += (2 + dpcheck(i,j-1,k-1,grid,dp));
//             }else{
//                 count2 = dpcheck(i,j-1,k,grid,dp);
//             }
//         }
//         return dp[i][j][k] = max(count1,count2);
//     }
//     int maxPathScore(vector<vector<int>>& grid, int k) {
//         int n = grid.size();  int m = grid[0].size();
//         vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (m+1, vector<int> (k+1,-1)));
//         return dpcheck(n-1,m-1,k,grid,dp) == INT_MIN ? -1 : dpcheck(n-1,m-1,k,grid,dp);
//     }
// };

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        dp[0][0][0] = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int cost = 0; cost <= k; cost++) {
                    if(dp[i][j][cost] == -1) continue;
                    
                    int currentScore = dp[i][j][cost];
        
                    if(j + 1 < n) {
                        int newCost = cost;
                        int newScore = currentScore;
                        
                        if(grid[i][j + 1] == 1) {
                            newCost = cost + 1;
                            newScore = currentScore + 1;
                        } else if(grid[i][j + 1] == 2) {
                            newCost = cost + 1;
                            newScore = currentScore + 2;
                        } else {
                            newCost = cost;
                            newScore = currentScore;
                        }
                        
                        if(newCost <= k) {
                            dp[i][j + 1][newCost] = max(dp[i][j + 1][newCost], newScore);
                        }
                    }
                    if(i + 1 < m) {
                        int newCost = cost;
                        int newScore = currentScore;
                        
                        if(grid[i + 1][j] == 1) {
                            newCost = cost + 1;
                            newScore = currentScore + 1;
                        } else if(grid[i + 1][j] == 2) {
                            newCost = cost + 1;
                            newScore = currentScore + 2;
                        } else {
                            newCost = cost;
                            newScore = currentScore;
                        }
                        
                        if(newCost <= k) {
                            dp[i + 1][j][newCost] = max(dp[i + 1][j][newCost], newScore);
                        }
                    }
                }
            }
        }

        int result = -1;
        for(int cost = 0; cost <= k; cost++) {
            if(dp[m - 1][n - 1][cost] != -1) {
                result = max(result, dp[m - 1][n - 1][cost]);
            }
        }
        
        return result;
    }
};