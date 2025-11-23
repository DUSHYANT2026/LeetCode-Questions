// class Solution {
// private: 
//     int recursolve(int indx,vector<int> &nums,int sum){
//         if(indx == nums.size()){
//             if(sum%3 == 0){
//                 return sum;
//             }
//             return INT_MIN;
//         }
//         int pick = nums[indx] + recursolve(indx+1,nums,(sum+nums[indx]));
//         int notpick = recursolve(indx+1,nums,sum);

//         return max(pick,notpick); 
//     }
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         int sum=0;
//         return recursolve(0,nums,sum);
//     }
// };
class Solution {
public:
     int solve(int i, int curr_sum_rem,vector<int>& nums,vector<vector<int>>&dp){
    if(i>=nums.size()){
        if(curr_sum_rem==0){
            return 0;
        }
        return INT_MIN;
    }
    if(dp[i][curr_sum_rem]!=-1)
        return dp[i][curr_sum_rem];
    int pick =nums[i]+ solve(i+1,(curr_sum_rem+nums[i])%3,nums,dp);    
    int notpick =0+ solve(i+1,curr_sum_rem,nums,dp);  
    return dp[i][curr_sum_rem]=max(pick,notpick);
    
}
    
    int maxSumDivThree(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> dp(n,vector<int>(3,-1)); 
        return solve(0,0,nums,dp);
    }
};