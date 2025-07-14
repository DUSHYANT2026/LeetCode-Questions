// class Solution {
// public:
//     char processStr(string s, long long k) {
//         string ans = "";
//         for(auto it : s){
//             if(it == '#' && !ans.empty()){
//                 string temp = ans;
//                 ans = ans+temp;
//             }
//             else if(it == '%' && !ans.empty()){
//                 reverse(ans.begin(),ans.end());
//             }
//             else if(it == '*' && !ans.empty()){
//                 ans.pop_back();
//             }
//             else if(it != '#' && it != '*' && it != '%'){
//                 ans += it;
//             }
//         }
//         cout<<ans<<endl;
//         if(ans.size() <= k || ans.size() == 0) return '.';
//         return ans[k];
//     }
// };



class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(auto c:s){
            if(islower(c)) len++;
            else if(c=='*' && len>0) len--;
            else if(c=='#') len *= 2;
        }
        if(k >= len) return '.';

        for(int i = s.size()-1; i >= 0; --i){
            char c = s[i];
            if(islower(c)) {
                if(k == len - 1) return c;
                len--;
            }
            else if(c == '*') len++;
            else if(c == '#') {
                len /= 2;
                if(k >= len) k -= len;
            }
            else if(c == '%') {
                k = len - 1 - k;
            }
        }
        return '.';
    }
};