class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int,int> mapp;
        for(auto it : logs){
            for(int i=it[0]; i<= it[1]; i++) mapp[i]++;
        }
        vector<pair<int,int>> nums;
        for(auto it : mapp){ nums.push_back({it.second,it.first}); }
        auto custom = [](pair<int,int> &a, pair<int,int>& b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        sort(nums.rbegin(),nums.rend(),custom);
        return nums[0].second;
    }
};