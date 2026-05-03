class Solution {
public:
    bool primenumber(int n){
        if(n <= 1) return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int newn = stoi(s);

        int ans = 0;
        for(int i=min(n,newn); i<= max(newn, n); i++){
            if(primenumber(i)) ans += i;
        }
        return ans;
    }
};