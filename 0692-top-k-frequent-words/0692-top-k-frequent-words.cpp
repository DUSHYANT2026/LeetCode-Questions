class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mapp; for(auto it : words) mapp[it]++;
        vector<pair<int,string>> nums;
        for(auto it : mapp) nums.push_back({it.second,it.first});
        auto custom = [](pair<int,string> &a, pair<int,string> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        sort(nums.rbegin(),nums.rend(),custom);
        for(int i=0; i<k; i++) ans.push_back(nums[i].second);
        return ans;
    }
};