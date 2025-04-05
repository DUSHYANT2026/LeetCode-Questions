// class Solution {
// private:
//     int dpsolve(int i, int j , int n, int m, vector<vector<int>>& dp, vector<vector<int>>& nums){
//         if(i == n-1) return nums[n-1][j];

//         if(dp[i][j] != -1) return dp[i][j];
//         int count1 = INT_MAX; int count2 = INT_MAX; int count3 = INT_MAX;
//         if(i < n-1){
//             count1 = nums[i][j] + dpsolve(i+1,j,n,m,dp,nums); 
//         }
//         if(i < n-1 && j < m-1){
//             count2 = nums[i][j] + dpsolve(i+1,j+1,n,m,dp,nums);
//         }
//         if(i < n-1 && j > 0){
//             count3 = nums[i][j] + dpsolve(i+1,j-1,n,m,dp,nums);
//         }
//         return dp[i][j] = min({count1, count2, count3});
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& nums) {
//         int n = nums.size(); int m = nums[0].size();
//         vector<vector<int>> dp(n, vector<int> (m,-1));
//         int ans = INT_MAX;
//         for(int j=0; j<m; j++){
//             ans = min(ans, dpsolve(0,j,n,m,dp,nums));
//         } 
//         return ans;
//     }
// };









class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size(); int m = nums[0].size();
        vector<vector<int>> dp (n,vector<int> (m,-1));
       
        for(int j=0; j<m; j++) dp[0][j] = nums[0][j];

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                    int down = INT_MAX; int dgleft = INT_MAX; int dgright = INT_MAX;

                    down = nums[i][j] + dp[i-1][j];

                    if(j > 0) dgleft = nums[i][j] + dp[i-1][j-1];
                    else dgleft = INT_MAX;
            
                    if(j < m-1) dgright = nums[i][j] + dp[i-1][j+1];
                    else dgright = INT_MAX;

                    dp[i][j] = min(down,min(dgleft,dgright));
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<m; j++) ans = min(ans,dp[n-1][j]);
        return ans;
    }
};