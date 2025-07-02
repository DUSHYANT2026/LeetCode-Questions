class Solution {
public:
    int possibleStringCount(string word, int k) {
        vector<int> v;
        int cnt=1;
        int n=word.size();
        int chk=0;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1])cnt++;
            else{
                if(cnt>1)v.push_back(cnt-1);
                cnt=1;chk++;
            }
        }
        if(cnt>1)v.push_back(cnt-1);
        cnt=1;chk++;
        const int mod=(int)1e9+7;
        if(chk>=k){
            int ans=1;
            for(auto &x:v){
                ans=(ans*1ll*(x+1))%mod;
            }
            return ans;
        }
        k-=chk;
        vector<int> dp(k,0),pref(k,0);
        for(int i=v.size();i>=0;i--){
            for(int r=k-1;r>=0;r--){
                if(i==v.size()){
                    dp[r]=1;continue;
                }
                int mn=0,mx=min(r,v[i]);
                int l=r-mx,ra=r;
                int sum=pref[ra];
                if(l)sum=(sum-pref[l-1])%mod;
                dp[r]=sum;
            }
            pref[0]=dp[0];
            for(int r=1;r<k;r++)pref[r]=(pref[r-1]+dp[r])%mod;
        }
        int ans=1;
        for(auto &x:v){
            ans=(ans*1ll*(x+1))%mod;
        }
        ans=(ans-dp[k-1])%mod;
        ans=(ans+mod)%mod;
        return ans;

    }
};