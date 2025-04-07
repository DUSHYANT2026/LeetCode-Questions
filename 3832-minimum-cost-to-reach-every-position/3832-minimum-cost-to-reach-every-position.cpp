class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int change = 101;
        for(auto it : cost){
            change = min(change,it);
            if(change > it) ans.push_back(it);
            else ans.push_back(change);
        }
        return ans;
    }
};