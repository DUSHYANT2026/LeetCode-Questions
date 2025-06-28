class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<nums.size(); i++) pq.push({nums[i],i});

        vector<pair<int,int>> ans;
        while(k-- && !pq.empty()){
            auto it = pq.top(); pq.pop();
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin(),ans.end());
        vector<int> temp;
        for(auto  it : ans) temp.push_back(it.second);
        return temp;
    }
};