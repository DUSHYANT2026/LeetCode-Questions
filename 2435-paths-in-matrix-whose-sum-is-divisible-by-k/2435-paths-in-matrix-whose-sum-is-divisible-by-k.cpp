class Solution {
private:
    int mod = 1000000007;
    int dpcheck(int i, int j, int ans, vector<vector<vector<int>>> &dp,vector<vector<int>> &grid, int k){
        
        ans = (ans + grid[i][j])%k;
        if(i == 0 && j == 0) return ans == 0 ? 1 : 0;
        if(dp[i][j][ans] != -1) return dp[i][j][ans];

        
        int count = 0; int count1 = 0;
        if(i > 0){
            count = dpcheck(i-1,j,ans,dp,grid,k);
        }
        if(j > 0){
            count1 = dpcheck(i,j-1,ans, dp, grid,k);
        }
        return dp[i][j][ans] = (count+count1)%mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return dpcheck(n-1,m-1,0,dp,grid,k);
    }
};