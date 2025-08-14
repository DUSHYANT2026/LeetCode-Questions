class Solution {
private:
    int dpcheck1(int i, int j, int n, int m, vector<vector<int>> &dp1, vector<vector<int>> &nums){
        if(i == n-1 && j == m-1) return 0;
        if(i >= n || j < 0 || j >= m || i > j || i == j) return 0;

        if(dp1[i][j] != -1) return dp1[i][j];
        int count1 = nums[i][j] + dpcheck1(i+1,j,n,m,dp1,nums);
        int count2 = nums[i][j] + dpcheck1(i+1,j-1,n,m,dp1,nums);
        int count3 = nums[i][j] + dpcheck1(i+1,j+1,n,m,dp1,nums);

        return dp1[i][j] = max({count1,count2,count3});
    }
private:
    int dpcheck2(int i, int j, int n, int m, vector<vector<int>> &dp2, vector<vector<int>> &nums){
        if(i == n-1 && j == m-1) return 0;

        if(i < 0 || i >= n || j >= m || j > i || i ==  j) return 0;

        if(dp2[i][j] != -1) return dp2[i][j];
        int count1 = nums[i][j] + dpcheck2(i-1,j+1,n,m,dp2,nums);
        int count2 = nums[i][j] + dpcheck2(i,j+1,n,m,dp2,nums);
        int count3 = nums[i][j] + dpcheck2(i+1,j+1,n,m,dp2,nums);

        return dp2[i][j] = max({count1,count2,count3}); 
    }
public:
    int maxCollectedFruits(vector<vector<int>>&  nums) {
        int ans = 0; int n = nums.size(); int m = nums[0].size();

        for(int i=0; i<n;  i++){
            for(int j=0; j<m; j++){
                if(i == j){
                    ans += nums[i][j];
                }
            }
        }
        vector<vector<int>> dp1 (n, vector<int> (m,-1));
        vector<vector<int>> dp2 (n, vector<int> (m,-1));
        return ans + dpcheck1(0,m-1,n,m,dp1,nums) + dpcheck2(n-1,0,n,m,dp2,nums); 
    }
};