class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mapp;
        for(auto it : s){
            mapp[it]++;
        }
        int ans = 0;
        int mark = false;
        for(auto it : mapp){
            ans += it.second/2 * 2;
            if(it.second%2 != 0){
                mark = true;
            }
        }
        if(mark == true){
            return ans+1;
        }
        return ans;
    }
};