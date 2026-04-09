class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7;
        int n = nums.size();
        vector<long long> ansnums;
        for(auto it : nums) ansnums.push_back(it);

        for(auto it : queries){
            int idx = it[0];
            int ri = it[1];
            int vi = it[3]; int ki = it[2];
            while(idx <= ri){
                ansnums[idx] = (long long)(ansnums[idx] * vi) % mod;
                idx += ki;
            }
        }

        int ans = 0;
        for(auto it : ansnums){
            ans ^= it;
        }
        return ans;
    }
};