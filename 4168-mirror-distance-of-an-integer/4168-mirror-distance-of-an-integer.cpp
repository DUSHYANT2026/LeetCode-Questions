class Solution {
public:
    int check(int n){
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int mirrorDistance(int n) {
        return abs(n - check(n));
    }
};