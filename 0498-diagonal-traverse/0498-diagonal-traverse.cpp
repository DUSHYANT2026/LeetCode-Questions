class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        map<int,vector<int>> mapp;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                mapp[i+j].push_back(nums[i][j]);
            }
        }
        int level = 1;
        for(auto it : mapp){
            vector<int>v = it.second;
            if(level%2 != 0){
                reverse(v.begin(),v.end());
            }
            for(int x : v){
                ans.push_back(x);
            }
            level++;
        }
        return ans;
    }
};