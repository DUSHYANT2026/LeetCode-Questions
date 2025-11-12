// class Solution {
// public:
//     long long maxProduct(vector<int>& nums) {
//         vector<pair<long long,bool>> temp;

//         for(auto it : nums){
//             if(it >= 0) temp.push_back({it,true});
//             else temp.push_back({abs(it),false});
//         }
//         sort(temp.begin(),temp.end());
//         int n = nums.size();
//         bool mark1 = temp[n-1].second;
//         bool mark2 = temp[n-2].second;
//         long long num1 = temp[n-1].first;
//         long long num2 = temp[n-2].first;
//         return num1*num2*1e5;
//     }
// };



class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) nums[i] = abs(nums[i]);
        sort(nums.begin(),nums.end());
        return (long long)nums[nums.size()-1] * (long long)nums[nums.size()-2] * 1e5;
    }
};