class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it : mapp) pq.push({it.second,it.first});

        while(k--){
            auto it = pq.top(); pq.pop();
            ans.push_back(it.second);
        } 
        return ans;
    }
};