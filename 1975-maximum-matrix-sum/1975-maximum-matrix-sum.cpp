class Solution {
public:
    long long min(long long a,long long b){
        if(a<b)
            return a;
        return b;
    }
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        long mini=INT_MAX;
        int cnt=0;
        for(auto row:matrix){
            for(auto it:row){
                mini=min(mini,abs((long long)it));
                if(it<0){
                    sum-=it;
                    cnt++;
                }
                else 
                    sum+=it;
            }
    
        }
        return (cnt&1)?sum-2*mini:sum;
    }
};