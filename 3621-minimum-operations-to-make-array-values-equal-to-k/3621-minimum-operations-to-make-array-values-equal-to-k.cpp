class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto it : nums) {
            if(it < k) return -1;
        }
        set<int> s; for(auto it : nums) s.insert(it); int count = 0; for(auto it : s){ if(it >  k) count++;} return count;
    }
};