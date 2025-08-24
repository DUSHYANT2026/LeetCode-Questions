class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;

        int x = n/k;

        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;

        for(auto it : mapp){
            if(it.second > x) return false;
        }
        return true;
    }
};