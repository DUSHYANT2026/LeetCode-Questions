class Solution {
private:
    int dpcheck(int i, int j, int n, int m, vector<vector<int>>& nums, vector<vector<int>>& dp){
        if(i == n-1 && j == m-1) return max(1,1-nums[i][j]);

        if(dp[i][j] != -1) return dp[i][j];
        int count1 = INT_MAX; int count2 = INT_MAX;
        if(i < n-1){
            count1 = dpcheck(i+1,j,n,m,nums,dp);
        }
        if(j < m-1){
            count2 = dpcheck(i,j+1,n,m,nums,dp);
        }
        int check = min(count1,count2) - nums[i][j];
        return dp[i][j] = max(1,check);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& nums) {
        int n = nums.size(); int m = nums[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return dpcheck(0,0,n,m,nums,dp);
    }
};