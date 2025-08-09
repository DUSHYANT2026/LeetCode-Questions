// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> ans = {-1,-1};

//         int s=0;
//         int e=nums.size()-1;

//         while(s<=e){
//             int mid = (s+e)/2;
//             if(nums[mid] == target){
//                 ans[0] = mid;
//                 e=mid-1;
//             }
//             else if(nums[mid] < target){
//                 s=mid+1;
//             }
//             else{
//                 e=mid-1;
//             }
//         }

//          s=0;
//          e=nums.size()-1;

//          while(s<=e){
//             int mid = (s+e)/2;
//             if(nums[mid] == target){
//                 ans[1] = mid;
//                 s=mid+1;
//             }
//             else if(nums[mid] < target){
//                 s=mid+1;
//             }
//             else{
//                 e=mid-1;
//             }
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        if(find(nums.begin(),nums.end(),target) != nums.end()){
            ans[0] = (lower_bound(nums.begin(),nums.end(),target) - nums.begin());
            ans[1] = (upper_bound(nums.begin(),nums.end(),target) - nums.begin()) - 1;
        }
        return ans;
    }
};