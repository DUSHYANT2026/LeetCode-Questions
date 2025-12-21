// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         unordered_map<int, int> mapp;
//         int count = 0;
//         vector<int> temp;
//         int n = nums.size();

//         for(int x : nums) mapp[x]++;

//         for(int i = 0; i < n; i++) {
//             bool hasDuplicate = false;
//             for(auto const& [val, freq] : mapp) {
//                 if(freq > 1) {
//                     hasDuplicate = true;
//                     break;
//                 }
//             }
//             if(!hasDuplicate) return count;

//             temp.push_back(nums[i]);

//             if(temp.size() == 3 || i == n - 1) {
//                 count++;
//                 for(int val : temp) {
//                     mapp[val]--;
//                 }
//                 temp.clear();
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> hash;
        int i = 0;
        for(i = nums.size() - 1; i >= 0; i--) {
            if (hash.count(nums[i])) break;
            hash.insert(nums[i]);
        }
        return (i + 3) / 3;
    }
};