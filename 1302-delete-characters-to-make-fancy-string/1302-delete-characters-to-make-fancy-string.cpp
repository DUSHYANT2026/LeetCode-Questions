class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans += s[0];
        if(s.size() < 3) return s;
        for(int i=1; i<s.size()-1; i++){
            ans += s[i];
            if(s[i-1] == s[i] && s[i] == s[i+1]){
                ans.pop_back();
            }
        }
        ans += s[s.size()-1];
        // if(s[0] == s[1] && s[1] == s[2]){
        //     ans = ans;
        // }else ans = s[0] + ans;

        // if(s[s.size()-1] == s[s.size()-2] && s[s.size()-3] == s[s.size()-2]){
        //     ans = ans;
        // }else ans += s[s.size()-1];


        
        return ans;
    }
};