class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto it : nums){
            maxi = max(maxi,it);
        }
        if(maxi != nums.size()-1){
            return false;
        }
        unordered_map<int,int> mapp;
        for(auto it : nums){
            mapp[it]++;
        }
        for(auto it : mapp){
            if(it.first == maxi){
                if(it.second == 2 && mapp.size()+1 == nums.size()){
                    return true;
                }
            }
        }
        return false;
    }
};