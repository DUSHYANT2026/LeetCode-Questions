class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        if(nums.size() % k != 0) return false;
        int group = nums.size()/k;

        sort(nums.begin(),nums.end());
        for(auto it : nums) mapp[it]++;

        for(auto it : nums){
            if(mapp[it]){
                for(int i=it; i<it+k; i++){
                    if(mapp[i] <= 0) return false;
                    mapp[i]--;
                }
            }
        }
        return true;
    }
};