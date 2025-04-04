class Solution {
private:
    int dpsolve(int i, int j,int n, vector<vector<int>>& dp, vector<vector<int>>& nums){
        if(i == n-1) return nums[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];

        int count1 = INT_MAX; int count2 = INT_MAX;
        if(j < n-1) count1 = nums[i][j] + dpsolve(i+1,j,n,dp,nums);
        if(j < n-1) count2 = nums[i][j] + dpsolve(i+1,j+1,n,dp,nums);

        return dp[i][j] = min(count1,count2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return dpsolve(0,0,n,dp,triangle);
    }
};