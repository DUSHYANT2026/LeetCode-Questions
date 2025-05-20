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
        
        int ans = INT_MAX;

        for(int k=0; k<m; k++) {
            int cost = grid[i][j] + moveCost[grid[i][j]][k] + dpcheck(i+1,k, n, m, dp, grid, moveCost);
            if(cost < ans){
                ans = cost;
            }
        }
        return dp[i][j] = ans;
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






// int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//     int m = grid.size(), n = grid[0].size();
//     vector<vector<int>> visitedCost(m, vector<int>(n, INT_MAX));
//     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

//     for(int j=0; j<n; j++)
//         pq.push({grid[0][j], 0, j});

//     while(!pq.empty()){
//         int costTillHere = pq.top()[0];
//         int x = pq.top()[1];
//         int y = pq.top()[2];
//         pq.pop();

//         if(x == m-1)
//             return costTillHere;

//         for(int dy = 0; x+1 < m && dy < n; dy++){
//             int newCost = costTillHere  + moveCost[grid[x][y]][dy] + grid[x+1][dy];
//             if(newCost < visitedCost[x+1][dy]){
//                 visitedCost[x+1][dy] =  newCost;
//                 pq.push({newCost, x+1, dy});
//             }
//         }
//     }
//     return -1;
// }