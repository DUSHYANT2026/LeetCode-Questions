class Solution {
private:
    bool dpcheck(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        if(i == 0 && j == 0) return true;
        if(i == 0) return false;
        if(j == 0){
            for(int x=1; x<=i; x++){
                if(s[x-1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] !=  -1) return dp[i][j];

        if(s[i-1] == t[j-1] || s[i-1] == '?'){
            return dp[i][j] = dpcheck(i-1,j-1,s,t,dp);
        }else if(s[i-1] == '*'){
            return dp[i][j] = dpcheck(i,j-1,s,t,dp) || dpcheck(i-1,j,s,t,dp);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(); 
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return dpcheck(n,m,p,s,dp);
    }
};