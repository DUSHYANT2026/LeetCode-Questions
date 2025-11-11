class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mapp;
        for(int i=0; i<nums.size(); i++) mapp[nums[i]].push_back(i);

        int ans = INT_MAX;
        for(auto it : mapp){
            vector<int> v = it.second;
            if(v.size() >= 3){
                sort(v.begin(),v.end());
                for(int i=1; i<v.size()-1; i++){
                    ans = min(ans, 2* ( ( max(v[i+1] , (max(v[i-1],v[i])))) -   (min(min(v[i-1],v[i]),v[i]))  ));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};