class Solution {
public:
    string toHex(int n) {
        if(n == 0) return "0";
        string ans = "";
        unsigned int num = n;
        string temp = "0123456789abcdef";

        while(num != 0){
            ans = temp[num%16] + ans;
            num = num/16;
        }
        return ans;
    }
};