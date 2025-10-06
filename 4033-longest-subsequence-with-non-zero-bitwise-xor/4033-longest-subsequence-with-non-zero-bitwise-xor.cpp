class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(); int ans = 0; bool mark = true; for(auto it : nums){ ans ^= it; if(ans) mark = false;}  if(ans) return n; else if(!mark) return n-1; return 0;
    }
};