class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> s; for(auto it : nums) s.insert(it); for(int i=0; i<=nums.size(); i++) { if(s.find(i) == s.end()) return i;} return -1;
    }
};