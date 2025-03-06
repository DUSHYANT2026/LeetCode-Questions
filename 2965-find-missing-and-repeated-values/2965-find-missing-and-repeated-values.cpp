class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mapp;
        for(auto it : grid) { for(auto i : it) mapp[i]++; }
        int ans1 = 0, ans2 = 0;
        for(auto it : mapp){ if(it.second > 1) ans1 = it.first; }
        for(int i=1; i<=grid.size()*grid[0].size(); i++){
            if(mapp.find(i) == mapp.end()) ans2 = i;
        }
        return {ans1, ans2};
    }
};