class Solution {
private:
    int dpsolve(string &s, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        if (i > j) return 0;  
        if (i == j) return 1; 
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int res = 0;
        int diff = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
        if (diff <= k) {
            res = 2 + dpsolve(s, i + 1, j - 1, k - diff, dp); 
        }
        return dp[i][j][k] = max({res, dpsolve(s, i + 1, j, k, dp), dpsolve(s, i, j - 1, k, dp)});
    }

public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return dpsolve(s, 0, n - 1, k, dp);
    }
};



