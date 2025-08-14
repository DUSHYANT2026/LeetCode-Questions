// class Solution {
// private:
//     int dpcheck(int i, int j, vector<vector<int>>& nums,vector<vector<int>>& dp){  // using top-down method
//         if(i >= 0 && j >= 0 && nums[i][j] == 1) return 0;
//         if(i == 0 && j == 0) return 1;
//         if(i < 0 || j < 0) return 0;

//         if(dp[i][j] != -1) return dp[i][j];
//         int up = dpcheck(i-1,j,nums,dp);
//         int left = dpcheck(i,j-1,nums,dp);

//         return dp[i][j] = (up + left);  
        
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& nums) {
//         int n = nums.size(); int m = nums[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));

//         return dpcheck(n-1, m-1,nums,dp);
//     }
// };


// class Solution {
// private:
//     int dpcheck(int i, int j, int n , int m, vector<vector<int>>& nums,vector<vector<int>>& dp){    // using bottom-up approch
//         if(i >= n || j >= m || nums[i][j] == 1) return 0;
//         if(i == n-1 && j == m-1) return 1;
//         if(i >= n || j >= m  ) return 0;

//         if(dp[i][j] != -1) return dp[i][j];
//         int up = dpcheck(i+1,j,n,m,nums,dp);
//         int left = dpcheck(i,j+1,n,m,nums,dp);

//         return dp[i][j] = (up + left);  
        
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& nums) {
//         int n = nums.size(); int m = nums[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));

//         return dpcheck(0,0,n,m,nums,dp);
//     }
// };






class Solution {
private:
    int dfscheck(int i, int j, int n, int m, vector<vector<int>>& dp, vector<vector<int>>& nums){
        if(nums[i][j] == 1 || i >= n-1 || j >= m-1) return 0;
        if(i == n-1 && j == m-1 && grid[i][j] != 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        int count1 = 0; int count2 = 0; 
        if(grid[i][j] != 1 && i <= n-1){
            count1 = dfscheck(i+1,j,n,m,dp,nums);
        }
        if(grid[i][j] != 1 && j <= m-1){
            count2 = dfscheck(i,j+1,n,m,dp,nums);
        }
        return dp[i][j] = (count1+count2);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size(); int m = nums[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dfscheck(0,0,n,m,dp,nums);
    }
};