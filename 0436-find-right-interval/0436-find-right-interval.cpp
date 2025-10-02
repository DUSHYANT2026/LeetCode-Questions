class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
    
        map<int, int> mapp;
        for(int i=0; i<n; i++){
            mapp[nums[i][0]] = i;

        }
        for(int i=0; i<n; i++){
            int element = nums[i][1];
            auto it = mapp.lower_bound(element);
            if(it != mapp.end()){
                ans[i] = it->second;
            }
        }
        return ans;
    }
};