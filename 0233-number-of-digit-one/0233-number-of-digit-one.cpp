// class Solution {
// public:
//     int oncount(int n){
//         int count = 0; 
//         while(n != 0){
//             int x = n%10;
//             if(x == 1) count++;
//             n /= 10;
//         }
//         return count;
//     }
//     int totalcount(int n, vector<int>& dp){
//         if(n < 1) return 0;
//         if(dp[n] != -1) return dp[n]; 
//         return dp[n] = oncount(n) + totalcount(n-1 , dp);;
//     }
//     int countDigitOne(int n) {
//         vector<int> dp(n+1, -1);
//         return totalcount(n,dp);
//     }
// };



class Solution {
public:
int countDigitOne(int n) {
    if(n<1) return 0;
    if(n>=1 && n<10) return 1;
    int y=1, x=n;
    while(!(x<10)){
        x/=10;
        y*=10;
    }
    if(x==1)
        return n-y+1+countDigitOne(y-1)+countDigitOne(n%y);
    else
        return y+x*countDigitOne(y-1)+countDigitOne(n%y);
}
};
