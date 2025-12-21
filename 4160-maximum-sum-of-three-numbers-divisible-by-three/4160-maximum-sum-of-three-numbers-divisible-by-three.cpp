// class Solution {
// public:
//     void dpcheck(int i, vector<int> temp, int& ans, vector<int> &nums){
//         if(temp.size() == 3){
//             int sum = 0;
//             for(auto it : temp) sum += it;
//             if(sum%3 == 0){
//                 ans = max(ans, sum);
//             }
//             return;
//         }
//         if(i < 0) return;
//         temp.push_back(nums[i]);
//         dpcheck(i-1,temp,ans,nums);
//         temp.pop_back();
//         dpcheck(i-1,temp,ans,nums);
//     }
//     int maximumSum(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         vector<int> temp; 
//         dpcheck(n-1, temp, ans, nums);
//         return ans;
//     }
// };



class Solution {
public:
    int dpcheck(int i, int count, int sum, vector<int>& nums, vector<vector<vector<int>>> &dp){
        if(count == 3){
            if(sum == 0) return 0;
            return INT_MIN;
        }
        if(i < 0) return INT_MIN;
        if(dp[i][count][sum] != -1) return dp[i][count][sum];
        int ans = INT_MIN;
        ans = max(ans, dpcheck(i-1,count,sum,nums,dp));
        if(count < 3){
            ans = max(ans,  nums[i] + dpcheck(i-1, count + 1, (sum+nums[i])%3 , nums, dp));
        }
        return dp[i][count][sum] = ans;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(3,-1)));
        ans = max(ans, dpcheck(n-1,0,0,nums,dp));
        return ans;
    }
};