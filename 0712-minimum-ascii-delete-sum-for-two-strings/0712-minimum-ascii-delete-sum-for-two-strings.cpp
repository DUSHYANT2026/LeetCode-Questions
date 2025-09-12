// class Solution {
// public:
//     long long int dpcheck(long long int i,long long int j,string nums1,string nums2,vector<vector<int>> &dp){    // memoization (top-down)
//         if(i < 0 || j < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];

//         if(nums1[i] == nums2[j]){
//             return (nums1[i] - 0 + dpcheck(i-1,j-1,nums1,nums2,dp));
//         }
//         return max(dpcheck(i-1,j,nums1,nums2,dp),dpcheck(i,j-1,nums1,nums2,dp));
//     }
//     long long int minimumDeleteSum(string text1, string text2) {
//         long long int n = text1.size(); long long int m = text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
//         long long int count = dpcheck(n-1,m-1,text1,text2,dp);
//         long long int newcount = 2*count;

//         long long int sum = 0;
//         for(auto it : text1) sum += it-0;
//         for(auto it : text2) sum += it-0;

//         return sum - newcount;
//     }
// };


