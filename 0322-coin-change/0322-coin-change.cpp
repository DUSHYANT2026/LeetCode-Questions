class Solution {
private:
    int dpcheck(int index,vector<int> &nums,int amount,vector<vector<int>>&dp){
        if(index == 0){
            if(amount%nums[0] == 0) return amount/nums[0];
            return 1e9;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notcount = 0 + dpcheck(index-1,nums,amount,dp);
        int count = INT_MAX;
        if(nums[index] <= amount){
            count = 1 + dpcheck(index,nums,amount-nums[index],dp);
        }
        return dp[index][amount] = min(count,notcount);
    }
public:
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = dpcheck(n-1,nums,amount,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};