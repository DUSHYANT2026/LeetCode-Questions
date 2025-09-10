class Solution {
public:
    bool check(int n, vector<int> &nums){
        if(n < 0) return false;

        int temp = n;
        while(n != 1){
            for(auto it : nums){
                if(n%it == 0) n = n/it;
            }
            if(temp == n) return false;
            temp = n;
        }
        return true;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int count = 0;

        for(int i=1; i<INT_MAX; i++){
            if(check(i,primes)) count++;
            if(count == n) return i;
        }
        return n;
    }
};