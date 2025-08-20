class Solution {
public:
    int minSensors(int n, int m, int k) {
        int x = 2*k+1;
        int y = 0; int z = 0;
        if(n%x == 0) y = n/x;
        else y = n/x + 1;
        if(m%x == 0) z = m/x; 
        else z = m/x + 1;
    
        return y*z;
    }
};