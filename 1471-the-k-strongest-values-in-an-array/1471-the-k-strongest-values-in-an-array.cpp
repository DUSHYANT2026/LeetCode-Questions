class Solution {
public:
    vector<int> getStrongest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n  = nums.size();
        int x = (n-1)/2;

        vector<pair<int,int>> ans;
        for(int i=0; i<n; i++){
            ans.push_back({abs(nums[i]-nums[x]),nums[i]});
        }
        sort(ans.rbegin(),ans.rend());
        vector<int> check;
        for(int i=0; i<k; i++){
            check.push_back(ans[i].second);
        }
        return check;
    }
};