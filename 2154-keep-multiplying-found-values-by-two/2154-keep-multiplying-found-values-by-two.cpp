class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans = original;
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;
        int n = nums.size();
        while(n--){
            if(mapp.find(ans) != mapp.end()){
                ans = ans*2;
            }
            else break;
        }
        return ans;
    }
};