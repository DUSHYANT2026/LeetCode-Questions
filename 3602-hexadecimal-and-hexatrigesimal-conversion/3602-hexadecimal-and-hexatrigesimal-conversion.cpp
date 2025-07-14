class Solution {
public:
    string concatHex36(int n) {
        int x = n*n;
        int y = n*n*n;

        string nums1 = "0123456789ABCDEF";
        string nums2 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string s1 = "", s2 = "";
        while(x != 0){
            s1 = nums1[x%16] + s1;
            x = x/16; 
        }
        while(y != 0){
            s2 = nums2[y%36] + s2;
            y = y/36;
        }
        return s1 + s2;
    }
};