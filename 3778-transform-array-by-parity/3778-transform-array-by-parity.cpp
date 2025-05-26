class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> newnums;
        for(auto it : nums) {
            if(it%2 != 0) newnums.push_back(1);
            else newnums.push_back(0);
        }
        sort(newnums.begin(),newnums.end());
        return newnums;
    }
};