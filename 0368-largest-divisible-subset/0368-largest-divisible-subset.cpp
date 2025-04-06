class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        // int maxi=1;
        // int num=-1;
        // vector<int>ans;
        // vector<int>dp(n,1);
        // sort(arr.begin(),arr.end());
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if((arr[i]%arr[j]==0)&& dp[i]<dp[j]+1){
        //             dp[i]=dp[j]+1;
        //             if(maxi<dp[i]) maxi=dp[i];
        //         }
        //     }
        // }
        // for(int i=n-1;i>=0;i--){
        //     if(maxi==dp[i] && (num==-1 || (num%arr[i]==0))){
        //         ans.push_back(arr[i]);
        //         maxi--;
        //         num=arr[i];
        //     }
        // }
        // return ans;

        sort(arr.begin(),arr.end());

        vector<int> dp(n,1);
        vector<int> check(n);
        int lastindex = 0; int maxi = 0;
        
        for(int i=0; i<n; i++){
            check[i] = i;
            for(int j=0; j<i; j++){
                if(arr[i] % arr[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    check[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[lastindex]);
        
        while(check[lastindex] != lastindex){
            lastindex = check[lastindex];
            ans.push_back(arr[lastindex]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};