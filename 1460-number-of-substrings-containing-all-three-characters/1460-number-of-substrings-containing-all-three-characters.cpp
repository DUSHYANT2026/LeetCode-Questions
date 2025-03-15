class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count[3] = {0}; 
        int left = 0; 
        int result = 0;

        for (int right = 0; right < n; ++right) {
            ++count[s[right] - 'a'];
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                --count[s[left] - 'a'];
                ++left;
            }
            result += left;
        }

        return result;
    }
};
