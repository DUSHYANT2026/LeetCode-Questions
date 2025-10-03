class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        vector<pair<int,int>> ans;
        for(auto it : nums){
            ans.push_back({abs(it),it});
        }
        auto custom = [](pair<int,int> &a , pair<int,int> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        sort(ans.begin(),ans.end(),custom);
        return ans[0].second;
    }
};