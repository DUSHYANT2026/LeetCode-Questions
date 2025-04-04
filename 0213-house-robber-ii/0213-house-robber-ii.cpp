// class Solution {
// private:
//  int helper(vector<int>& temp) {
//         int n = temp.size();
//         vector<int> dp(n);;
//         dp[0] = temp[0];
//         int neg = 0;
//         for(int i =1;i<n;i++)
//         {
//             int take = temp[i];
//             if(i>1) take += dp[i-2];
//             int nottake = 0 + dp[i-1];
//             dp[i] = max(take,nottake);
//         }
//         return dp[n-1];
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp1, temp2;
//         if(n==1) return nums[0];
//         for(int i=0;i<n;i++)
//         {
//             if(i!=0) temp1.push_back(nums[i]);
//             if(i!=n-1) temp2.push_back(nums[i]);
//         }
//         return max(helper(temp1),helper(temp2));
//     }
// };


class Solution {
private:
    int dpcheck(vector<int> &dp,int index,vector<int> &nums){
        int n = nums.size();
        if(index == 0) return nums[0];
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];
        
        int take = nums[index] + dpcheck(dp,index-2,nums);
        int leave = dpcheck(dp,index-1,nums);

        return dp[index] = max(take,leave);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp1, temp2;
        if(n==1) return nums[0];

        for(int i=0;i<n;i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int n1 = temp1.size(); int n2 = temp2.size();
        vector<int> dp1(n1,-1), dp2(n2,-1);
        return max(dpcheck(dp1,n1-1,temp1),dpcheck(dp2,n2-1,temp2));
    }
};