class Solution {
private:
    bool dpcheck(int i, int sum, vector<int> &nums, vector<vector<int>> & dp){
        if(sum == 0) return true;
        if(i == 0) return sum == nums[0];

        if(dp[i][sum] != -1) return dp[i][sum];
        bool count = false; 
        if(sum >= nums[i]){
            count = dpcheck(i-1,sum-nums[i],nums,dp);
        }
        bool notcount = dpcheck(i-1,sum,nums,dp);
        return dp[i][sum] = (count || notcount);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum  = 0;
        for(auto it : nums) sum += it;
        int n =nums.size(); 
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return dpcheck(n-1,sum/2,nums,dp);
    }
};