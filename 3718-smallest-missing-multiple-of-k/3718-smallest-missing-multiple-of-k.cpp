class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;
        for(int i=k; i<INT_MAX; i+=k){
            if(mapp.find(i) == mapp.end()) return i;
        }
        return -1;
    }
};