class Solution {
public:
    bool validDigit(int n, int x) {
        bool mark = false;
        int y = 0;
        while(n > 0){
            y = n%10;
            if(y == x) mark = true;
            n = n/10;
        }
        return (mark && x != y) ? true : false;
    }
};