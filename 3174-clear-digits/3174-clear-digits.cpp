class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(auto it : s){
            if(isdigit(it)){
                ans.pop_back();
            }
            else{
                ans += it;
            }
        }
        return ans;
    }
};