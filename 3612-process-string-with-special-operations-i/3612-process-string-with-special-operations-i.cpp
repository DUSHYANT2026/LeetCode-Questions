class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto it : s){
            if(it == '#' && !ans.empty()){
                string temp = ans;
                ans = ans+temp;
            }
            else if(it == '%' && !ans.empty()){
                reverse(ans.begin(),ans.end());
            }
            else if(it == '*' && !ans.empty()){
                ans.pop_back();
            }
            else if(it != '#' && it != '*' && it != '%'){
                ans += it;
            }
        }
        return ans;
    }
};