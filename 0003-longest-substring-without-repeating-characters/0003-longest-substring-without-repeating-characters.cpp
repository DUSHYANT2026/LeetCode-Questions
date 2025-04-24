class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int start = -1;
        unordered_map<char,int> mapp;

        for(int i=0;i<s.size();i++){
            if (mapp.count(s[i]) != 0) {
                start = max(start, mapp[s[i]]);
            }
            mapp[s[i]] = i;
            count = max(count, i-start);
        }
        return count;
    }
};