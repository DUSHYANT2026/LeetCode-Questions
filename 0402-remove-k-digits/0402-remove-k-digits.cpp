class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == 1 && k == 1) return "0";
        string ans = "";
        stack<char> s;
        for(int i=0; i<num.size(); i++){
            while(!s.empty() && k > 0 && s.top() > num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(!s.empty()){
            ans += (s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        if(ans[i] == '0'){
            while(ans[i] == '0'){
                i++;
            }
        }
        string news = ans.substr(i,ans.size());
        return (news.size() == 0) ? "0" : news;
    }
};