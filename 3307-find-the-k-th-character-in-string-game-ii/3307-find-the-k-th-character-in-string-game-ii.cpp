class Solution {
public:
    vector<long long >pow;
    int solve(int ind,long long k,vector<int>&operations){
        if(ind<0)
            return 0;
        if(ind>=55)
            return solve(ind-1,k,operations);
        if(pow[ind]<k)
            return operations[ind]+solve(ind-1,k-pow[ind],operations);
        return solve(ind-1,k,operations);
    }
    char kthCharacter(long long k, vector<int>& operations) {
        pow.resize(55,1);
        for(int i=1;i<55;i++){
            pow[i]=pow[i-1]*2;
        }
        int n=operations.size();
        int ans=solve(n-1,k,operations);
        return 'a'+ans%26;
    }
};