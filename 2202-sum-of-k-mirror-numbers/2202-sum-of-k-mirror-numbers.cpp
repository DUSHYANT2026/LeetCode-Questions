class Solution {
public:
    int digit[100];
    bool check(long long x,int k){
        int len=-1;
        while(x){
            len++;
            digit[len]=x%k;
            x=x/k;
        }
        int i=0;
        int j=len;
        while(i<=j){
            if(digit[i]!=digit[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        int start=1;
        int cnt=0;
        long long ans=0;
        while(cnt<n){
            int end=start*10;
            for(int op=0;op<2;op++){
                for(int i=start;i<end && cnt<n ;i++){
                    long long comb=i;
                    int x=(op==0?i/10:i);
                    while(x){
                        comb=comb*10+x%10;
                        x/=10;
                    }
                    if(check(comb,k)){
                        cnt++;
                        ans+=comb;    
                    }
                }
            }
            start=end;
        }
        return ans;
    }
};