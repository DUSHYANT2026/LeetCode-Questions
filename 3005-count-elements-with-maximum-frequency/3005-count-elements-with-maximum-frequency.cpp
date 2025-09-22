class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for(auto it : nums){
            mapp[it]++;
        }
        int count = INT_MIN;
        int ans = 0;
        for(auto it : mapp){
            count = max(count,it.second);
        }
        for(auto it : mapp){
            if(it.second == count){
                ans += it.second;
            }
        }
        return ans;
    }
};