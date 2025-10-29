class Solution {
private:
    bool check(int n){
        if(n == 0) return false;
        return (n&(n+1)) == 0;
    }
public:
    int smallestNumber(int n) {
        int ans = 0;
        for(int i=n; i<100000; i++){
            if(check(i)){
                ans = i; break;
            }
        }
        return ans;
    }
};