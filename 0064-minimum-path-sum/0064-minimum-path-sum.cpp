class Solution {
private:
    int dpcheck(int i, int j, vector<vector<int>> &dp,vector<vector<int>> &grid){
        if(i == 0 && j == 0) return grid[0][0];

        if(dp[i][j] != -1) return dp[i][j];
        int count1 = INT_MAX; int count2 = INT_MAX;
        if(i > 0){
            count1 = grid[i][j] + dpcheck(i-1,j,dp,grid);
        }
        if(j > 0){
            count2 = grid[i][j] + dpcheck(i,j-1,dp,grid);
        }
        return dp[i][j] = min(count1,count2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return dpcheck(n-1,m-1,dp,grid);
    }
};