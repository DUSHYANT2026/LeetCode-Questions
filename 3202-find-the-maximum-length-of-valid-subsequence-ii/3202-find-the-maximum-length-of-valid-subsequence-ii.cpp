// class Solution {
// private:
//     int dpcheck(int i, vector<int>& nums, int preindex, int check, int k) {
//         if (i < 0) return 0;

//         int notcount = dpcheck(i - 1, nums, preindex, check,k);
//         int count = 0;
//         if (preindex == -1 || (nums[preindex] + nums[i]) % k == check) {
//             count = 1 + dpcheck(i - 1, nums, i, check , k);
//         }

//         return max(count, notcount);
//     }

// public:
//     int maximumLength(vector<int>& nums, int k) {
//         int n = nums.size(), ans = 0;

//         for (int i = 0; i <= k; i++) {
//             ans = max(ans, dpcheck(n - 1, nums, -1, i,k));
//         }
//         return ans;
//     }
// };



// class Solution {
// private:
//     int dpcheck(int i, vector<int>& nums, int preindex, int check, vector<vector<vector<int>>>& dp, int k) {
//         if (i < 0) return 0;
//         if (dp[i][preindex + 1][check] != -1) return dp[i][preindex + 1][check];

//         int notcount = dpcheck(i - 1, nums, preindex, check, dp, k);
//         int count = 0;
//         if (preindex == -1 || (nums[preindex] + nums[i]) % k == check) {
//             count = 1 + dpcheck(i - 1, nums, i, check, dp, k);
//         }

//         return dp[i][preindex + 1][check] = max(count, notcount);
//     }

// public:
//     int maximumLength(vector<int>& nums, int k) {
//         int n = nums.size(), ans = 0;
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(k, -1)));

//         for (int i = 0; i < k; i++) {
//             ans = max(ans, dpcheck(n - 1, nums, -1, i, dp, k));
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = (nums[i] + nums[j])%k;
                dp[i][temp] = max(dp[i][temp] , 1 + dp[j][temp]);
                ans = max(ans, dp[i][temp]);
            }
        }
        return ans+1;
    }
};

