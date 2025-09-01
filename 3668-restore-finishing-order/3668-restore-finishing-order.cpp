class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        unordered_map<int,int> mapp;
        for(auto it : friends) mapp[it]++;

        for(int i=0; i<order.size(); i++){
            if(mapp.find(order[i])!=mapp.end()) ans.push_back(order[i]);
        }
        return ans;
    }
};