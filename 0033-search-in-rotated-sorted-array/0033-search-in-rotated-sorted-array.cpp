class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int> mapp; for(int i=0; i<nums.size(); i++) mapp[nums[i]] = i;
        if(mapp.find(target) != mapp.end()) return mapp[target];
        return -1;
    }
};