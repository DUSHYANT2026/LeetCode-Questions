class Solution {
private:
    bool check(int n){
        string s = to_string(n);
        int size = s.size();
        if(size%2 == 1) return false;
        string s1 = s.substr(0,size/2);
        string s2 = s.substr(size/2);

        int sum1 = 0, sum2 = 0;
        for(char it : s1) sum1 += it - '0';
        for(char it : s2) sum2 += it - '0';
        return sum1 == sum2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            if(check(i)) count++;
        }
        return count;
    }
};