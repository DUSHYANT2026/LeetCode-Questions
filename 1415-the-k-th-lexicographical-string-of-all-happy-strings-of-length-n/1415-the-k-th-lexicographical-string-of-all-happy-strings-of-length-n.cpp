class Solution {
public:
    void backtrackcheck(int n,vector<string>& ans, string s){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        if(s.empty() || s.back() != 'a'){
            s.push_back('a');
            backtrackcheck(n,ans,s);
            s.pop_back();
        }
        if(s.empty() || s.back() != 'b'){
            s.push_back('b');
            backtrackcheck(n,ans,s);
            s.pop_back();
        }
        if(s.empty() || s.back() != 'c'){
            s.push_back('c');
            backtrackcheck(n,ans,s);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        backtrackcheck(n,ans,"");
        // sort(ans.begin(),ans.end());
        return (ans.size() < k ) ? "" : ans[k-1]; 
    }
};