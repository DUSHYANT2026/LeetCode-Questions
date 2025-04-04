class Solution {
private:
    int dpsolve(int index, vector<int>&nums, vector<int>& dp){
        if(index < 0 ) return 0;
        if(index == 0) return nums[index];

        if(dp[index] != -1) return dp[index];
        int count = 0; int notcount = 0;
        
        count = dpsolve(index - 2, nums, dp) + nums[index];
        if(index > 0)
        notcount = dpsolve(index - 1, nums, dp);

        return  dp[index] = max(count,notcount);
    }
public:
    int rob(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n+1,-1);
        return dpsolve(n-1,nums,dp);
    }
};