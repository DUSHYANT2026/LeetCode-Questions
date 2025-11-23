class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string temp = to_string(n);
        string ans = ""; long long sum = 0;

        for(auto it : temp){
            if(it != '0'){
                ans += it;
                sum += it-'0';
            }
        }
        long long x = stoll(ans);
        return  x * sum;
    }
};