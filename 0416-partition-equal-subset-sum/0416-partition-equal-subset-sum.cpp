class Solution {
private:
    bool dpsolve(int i, int sum, vector<vector<int>> &dp, vector<int> &nums){
        if(sum == 0) return true;
        if(i == 0) return sum == nums[0];

        if(dp[i][sum] != -1) return dp[i][sum];
        bool notcount = dpsolve(i-1,sum,dp,nums);
        bool count = false;
        if(nums[i] <= sum){
            count = dpsolve(i-1,sum-nums[i],dp,nums);
        }
        return dp[i][sum] = (count || notcount);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        int sum = 0; int nsum = 0;
        for(auto it : nums) sum += it;
        if(sum%2 != 0) return false;
        nsum = sum/2;
        vector<vector<int>> dp(n,vector<int> (nsum +1 , -1));
        return dpsolve(n-1,nsum,dp,nums);
    }
};