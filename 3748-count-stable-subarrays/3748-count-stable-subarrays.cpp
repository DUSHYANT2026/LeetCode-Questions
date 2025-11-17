// class Solution {
// private:
//     long long check(int s, int e, vector<int> &nums){
//         long long ans = 0;
//         long long count = 0;
//         for(int i=s; i<=e; i++){
//             if(i > s && nums[i-1] <= nums[i]){count++;}
//             else count = 1;
//             ans += count;
//         }
//         return ans;
//     }
// public:
//     vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<long long> ans;
//         for(auto it : queries){ ans.push_back(check(it[0],it[1],nums)); }
//         return ans;
//     }
// };



class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        if(nums.size() == 1) return {1}; 
        vector<long long> ans;

        long long count = 1;
        int n = nums.size();
        vector<long long> sum(n,0);
        sum[0] = 1; 
        for(int i=1; i<n; i++){
            if(nums[i-1] <= nums[i]){
                count++;
            }
            else{
                count = 1;
            }
            sum[i] = count;
        }
        for(auto it : queries){
            int s = it[0]; int e = it[1];
            long long temp = 0;

            for(int i=s; i<=e; i++){
                temp += sum[i];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};