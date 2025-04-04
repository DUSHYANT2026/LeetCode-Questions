class Solution {
private:
    int dpsolve(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int left = 0; int up = 0;
        if(i > 0)
        up = dpsolve(i-1,j,dp);
        if(j > 0)
        left = dpsolve(i,j-1,dp);

        return dp[i][j] = (left + up);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (n, vector<int> (m,-1));
        return dpsolve(n-1,m-1,dp); 
    }
};