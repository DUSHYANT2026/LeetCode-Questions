class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i=0;i<n;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mn=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j) mn=min(mn,grid[i][j]+dp[i-1][k]);
                    dp[i][j]=mn;
                }
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }

        return ans;
    }
};


