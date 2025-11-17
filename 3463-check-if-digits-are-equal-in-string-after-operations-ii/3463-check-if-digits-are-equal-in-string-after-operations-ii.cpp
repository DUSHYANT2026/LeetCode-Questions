// class Solution {
// public:
//     string check(string s){
//         string ans = "";

//         for(int i=0; i<s.size()-1; i++){
//             int x = s[i] - '0';
//             int y = s[i+1] - '0';
//             ans += (x+y)%10 + '0';
//         }
//         return ans;
//     }
//     bool hasSameDigits(string s) {
//         while(s.size() != 2){
//             string temp = check(s);
//             s = temp;
//         }
//         int ans = stoi(s);
//         return (ans%11 == 0) ? true : false;
//     }
// };



class Solution {  
public:
    int comb(int n, int r){  
        if (r > n) { return 0; }
        int res = 1;
        for (int t = 1; t <= n; ++t) { res *= t; }
        for (int t = 1; t <= r; ++t) { res /= t; }
        for (int t = 1; t <= n - r; ++t) { res /= t; }
        return res;
    }
    bool check(vector<int>& a, int mod){
        int res = 0;
        int n = a.size();
        for (int i = 0; i != n; ++i){
            int ncr = 1;
            int x = n - 1;
            int y = i;
            while (x && y){
                ncr = ncr * comb(x % mod, y % mod) % mod;
                x /= mod;
                y /= mod;
            }
            res = (res + ncr * a[i]) % mod;
        }
        return res == 0;
    }

    bool hasSameDigits(string s) {
        int n = s.size();
        vector<int> a(n - 1);
        for (int i = 0; i != n - 1; ++i){
            a[i] = (s[i] - '0') - (s[i + 1] - '0');
            a[i] = (a[i] + 10) % 10;
        }
        return check(a, 2) && check(a, 5);
    }
};