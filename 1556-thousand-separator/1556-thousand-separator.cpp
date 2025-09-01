class Solution {
public:
    string thousandSeparator(int n) {
        string ans = "";
        int count = 0;
        string s = to_string(n);
        reverse(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            ans += s[i];
            count++;
            if(count == 3){
                ans += ".";
                count = 0;
            }
        }
        if(ans[ans.size()-1] == '.') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};