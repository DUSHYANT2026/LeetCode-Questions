class Solution {
private:
    int dpsolve(int n, vector<int> &dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = dpsolve(n-1,dp) + dpsolve(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dpsolve(n,dp);
    }
};