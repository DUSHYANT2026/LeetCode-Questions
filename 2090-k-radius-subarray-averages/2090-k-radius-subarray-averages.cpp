// class Solution {
// public:
//     vector<int> getAverages(vector<int>& nums, int k) {
//         long long ssum = 0;
//         for(auto it : nums) ssum += it;
//         int n = nums.size();
//         vector<int> ans(n, -1);
//         if(n < 2*k+1) return ans;

//         for(int i=k; i<n-k; i++){
//             long long sum = ssum;
//             int j = 0; 
//             while(j < i-k){
//                 sum -= nums[j++];
//             }
//             int l = n-1; 
//             while(l > i+k){
//                 sum -= nums[l--];
//             }
//             ans[i] = sum/(2*k+1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if(n < 2*k+1) return ans;

        long long sum = 0;
        for(int i=0; i<2*k+1; i++){
            sum += nums[i];
        }
        ans[k] = sum/(2*k+1);      

        for(int i=k+1; i<n-k; i++){
            long long newsum = sum - nums[i-k-1] + nums[i+k];
            sum = newsum;
            ans[i] = newsum/(2*k+1);
            
        }
        return ans;
    }
};

