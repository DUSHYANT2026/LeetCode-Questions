class Solution {
private:
    int dpcheck(int index,vector<int> &nums,int amount,vector<vector<int>> &dp){
        if(index == 0){
            if(amount%nums[0] == 0) return 1;
            else return 0;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notcount = dpcheck(index-1,nums,amount,dp);
        int count = 0;
        if(nums[index] <= amount){
            count = dpcheck(index,nums,amount-nums[index],dp);
        }
        return dp[index][amount] = notcount + count;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return dpcheck(n-1,coins,amount,dp);
    }
};