class Solution {
private:
    int dpcheck(int index, vector<int> &nums, int sum, vector<vector<int>> &dp) {                    
        if (index == 0) {
            if (sum == 0 && nums[0] == 0) return 2; 
            if (sum == 0 || sum == nums[0]) return 1; 
            return 0;
        }
        if (dp[index][sum] != -1) return dp[index][sum];
        int notcount = dpcheck(index - 1, nums, sum, dp);
        int count = 0;
        if (sum >= nums[index])
            count = dpcheck(index - 1, nums, sum - nums[index], dp);   
        return dp[index][sum] = (count + notcount);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto it : nums) sum += it;

        if((sum-target)%2 != 0 || sum < target) return 0;

        int newsum = (sum-target)/2;
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(newsum+1,-1));
        return dpcheck(n-1,nums,newsum,dp);
    }
};