class Solution {
private:
    int dpsolve(int i, int j, vector<vector<int>> & dp){
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int count1 = 0; int count2 = 0;
        if(i > 0){
            count1 = dpsolve(i-1,j,dp);
        }
        if(j > 0){
            count2 = dpsolve(i,j-1,dp);
        }
        return dp[i][j] = (count1 + count2);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (n + 1, vector<int> (m + 1,-1));
        return dpsolve(n-1,m-1,dp);
    }
};