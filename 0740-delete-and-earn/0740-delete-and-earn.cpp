// class Solution {
// public:
//     int dpcheck(int index, vector<int> & dp, vector<int> &nums){
//         if(index < 0) return 0;

//         if(dp[index] != -1) return dp[index];
//         int count = 0; int notcount = 0;
//         count = nums[index] + dpcheck(index-2, dp, nums);
//         notcount = dpcheck(index-1,dp,nums);

//         return dp[index] = max(count,notcount);
//     }
//     int deleteAndEarn(vector<int>& nums) {
//         sort(nums.begin(), nums.end());  
//         int n = nums.size();
//         vector<int> newnums;
//         int x = nums[0];
//         int count = 1;
//         for(int i=1; i<n; i++){
//             if(nums[i] == nums[i-1]){
//                 count++;
//             }
//             else{
//                 newnums.push_back(nums[i-1]*count);
//                 count = 1;
//             }
//             x = max(x,nums[i]);
//         }
//         newnums.push_back(nums[n-1]*count);
//         vector<int> dp(x+1,-1);
//         return dpcheck(x-1,dp,newnums);
//     }
// };


class Solution {
public:
    int dpcheck(int index, vector<int> & dp, vector<int> &sum_values){
        if(index < 0) return 0;
        if(index == 0) return sum_values[0];

        if(dp[index] != -1) return dp[index];
        
        int pick = sum_values[index] + dpcheck(index-2, dp, sum_values);
        int not_pick = dpcheck(index-1, dp, sum_values);

        return dp[index] = max(pick, not_pick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int max_val = 0;
        for(int num : nums) {
            max_val = max(max_val, num);
        }

        vector<int> sum_values(max_val + 1, 0);
        for(int num : nums){
            sum_values[num] += num;
        }
        for(auto it : sum_values) cout<<it<<" "
        vector<int> dp(max_val + 1, -1);

        return dpcheck(max_val, dp, sum_values);
    }
};