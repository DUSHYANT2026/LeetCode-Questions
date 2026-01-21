class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(x == 2) {
                ans[i] = -1;
            } else {
                for(int bit = 0; bit < 31; bit++) {
                    if(!((x >> (bit + 1)) & 1)) {
                        ans[i] = x ^ (1 << bit);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};