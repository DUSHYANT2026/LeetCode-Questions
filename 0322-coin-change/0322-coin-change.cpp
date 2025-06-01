class Solution {
private:
    int dpcheck(int index, vector<int> &nums, int sum, vector<vector<int>> &dp){
        if(index == 0){
            if(sum % nums[index] == 0) return sum / nums[index];
            else return INT_MAX - 1;
        } 

        if(dp[index][sum] != -1) return dp[index][sum];

        int nottake = dpcheck(index - 1, nums, sum, dp); 
        int take = INT_MAX;
        if(sum >= nums[index]){
            take = 1 + dpcheck(index, nums, sum - nums[index], dp); 
        }
        return dp[index][sum] = min(take, nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = dpcheck(n - 1, coins, amount, dp);
        return (ans == INT_MAX || ans == INT_MAX - 1) ? -1 : ans; 
    }
};