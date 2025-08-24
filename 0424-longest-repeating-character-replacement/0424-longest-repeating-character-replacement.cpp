class Solution {
public:
     int characterReplacement(string s, int k) {
        unordered_map<char, int> mapp;
        int ans = 0;
        int j = 0;
        int maxcount = 0;

        for(int i = 0; i < s.size(); i++) {
            mapp[s[i]] = 1 + mapp[s[i]];
            maxcount = max(maxcount, mapp[s[i]]);

            if ((i - j + 1) - maxcount > k) {
                mapp[s[j]] -= 1;
                j++;
            } else {
                ans = max(ans, (i - j + 1));
            }
        }

        return ans;
    }
};
