class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int count = 1;

        for(int i=1; i<s.size(); i++){
            if(s[i-1] < s[i] && (s[i]-s[i-1] == 1)){
                count++;
                ans = max(ans,count);
            }
            else count = 1;
        }
        return ans;
    }
};