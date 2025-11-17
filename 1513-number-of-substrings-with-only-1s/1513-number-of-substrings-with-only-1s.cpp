class Solution {
public:
    int numSub(string s) {
        int n = s.size();

        vector<int> nums;
        int count = 0;
        const int MOD = 1000000007;

        for (int i = 0; i < n; i++) {
            int x = s[i] - '0';
            if (x == 1) {
                count++;
            } else {
                count = 0;
            }
            nums.push_back(count);
        }
        long long ans = 0; 
        for (int i = 0; i < nums.size(); i++) {
            ans = (ans + nums[i]) % MOD;
        }

        return ans;
    }
};
