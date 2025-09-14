class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;   priority_queue<int> pq;   vector<int> ans;
        for(auto it : nums) mapp[it]++;
        for(auto it : mapp) pq.push(it.first);
        while(!pq.empty() && k--){ ans.push_back(pq.top()); pq.pop();}
        return ans;
    }
};