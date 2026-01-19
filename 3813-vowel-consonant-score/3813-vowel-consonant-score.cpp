class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, space = 0, digit = 0;
        for(auto it : s){ 
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') v++;
            else if(it == ' ') space++;
            else if(isdigit(it)) digit++;
        }
        int c = s.size()-v-space-digit;
        return c == 0 ? 0 : floor(v/c);
    }
};