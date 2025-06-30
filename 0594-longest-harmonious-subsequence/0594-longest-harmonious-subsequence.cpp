class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mapp; for(auto it : nums) mapp[it]++;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(mapp.find(nums[i]+1) != mapp.end()){
                ans = max(ans,(mapp[nums[i]+1] + mapp[nums[i]]));
            }
        }
        return ans;
    }
};