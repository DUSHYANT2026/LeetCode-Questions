class Solution {
public:
    int dpcheck(int target, vector<int> &nums, vector<int> &dp) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        
        if (dp[target] != -1) return dp[target];
        
        int total = 0;
        for (int num : nums) {
            if (target >= num) {
                total += dpcheck(target - num, nums, dp);
            }
        }
        
        return dp[target] = total;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return dpcheck(target, nums, dp);
    }
};