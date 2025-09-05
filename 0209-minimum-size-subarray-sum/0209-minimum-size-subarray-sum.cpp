// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         int ans = INT_MAX;
//         for(int i=0;i<n;i++){
//             int sum = 0;
//             for(int j=i+1;j<n;j++){
//                 sum+=nums[j];
//                 if(sum >= target) count++;
//             }
//             ans = min(ans,count); 
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         int ans = INT_MAX;
//         int j = 0 ;
        
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             while(sum>=target){
//                 ans = min(ans,i-j+1);
//                 sum-=nums[j];
//                 j++;
//             }
//         }
//         if(ans == INT_MAX) return 0;
//         return ans;
//     }
// };




class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int j = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum >= target){
                while(sum >= target){
                    ans = min(ans, (i-j+1));
                    sum -= nums[j];
                    j++;
                }  
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};