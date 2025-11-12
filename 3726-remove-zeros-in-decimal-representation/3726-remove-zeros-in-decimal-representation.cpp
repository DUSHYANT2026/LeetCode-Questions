class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);

        string ans = "";
        for(auto it : s){
            if(it != '0'){
                ans += it;
            }
        }
        long long num = stoll(ans);
        return num;
    }
};