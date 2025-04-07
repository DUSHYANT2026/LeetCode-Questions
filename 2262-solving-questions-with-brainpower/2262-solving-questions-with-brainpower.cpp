class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int po=questions[i][0];
            int br=questions[i][1];
            int next=i+br+1;
            dp[i]=max((long long)po+((long long)next<n?dp[next]:0),dp[i+1]);
        }
        return dp[0];
    }
};