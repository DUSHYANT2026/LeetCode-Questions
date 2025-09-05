class Solution {
private:
    int dpcheck(int i, int j,int n, vector<vector<int>> &nums, vector<vector<int>>&dp){

        if(i == n-1) return nums[n-1][j];

        if(dp[i][j] != -2) return dp[i][j];

        int down = nums[i][j] + dpcheck(i+1,j,n,nums,dp);
        int left = nums[i][j] + dpcheck(i+1,j+1,n,nums,dp);

        return dp[i][j] = min(down,left);  
    }
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size(); 
        vector<vector<int>> dp(n,vector<int> (n,-2));
        return dpcheck(0,0,n,nums,dp);
    }
};
