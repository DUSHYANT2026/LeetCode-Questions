class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int sum = 0; int s = 0;
        unordered_map<int,int> mapp;
        for(int i=0; i<nums.size(); i++){
            if(mapp.count(nums[i]) != 0 && s <= mapp[nums[i]]){
                while(s <= mapp[nums[i]]){
                    sum -= nums[s];
                    s++;
                }
            }
            sum += nums[i];
            ans = max(sum,ans);
            mapp[nums[i]] = i;
        }
        return ans;
    }
};






// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int ans = 0;

//         for(int i=0; i<nums.size(); i++){
//             unordered_map<int,int> mapp;
//             int sum = 0;
//             for(int j=i; j<nums.size(); j++){
//                 if(mapp.count(nums[j]) == 0){
//                     sum += nums[j];
//                     ans = max(ans,sum);
//                 }
//                 else{
//                     mapp.clear();
//                     ans = max(ans,sum);
//                     sum = nums[j];
//                 }
//                 if(j == nums.size()-1) break;
//                 mapp[nums[j]]++;
//             }
//         }
//         return ans;
//     }
// };