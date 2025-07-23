class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int aCount=0;
        int bCount=0;
        int less=min(x,y);
        int ans=0;
        for(char c:s){
            if(c>'b'){
                ans+=min(aCount,bCount)*less;
                aCount=0;
                bCount=0;
            }
            else if(c=='a'){
                if(x<y && bCount>0){
                    bCount--;
                    ans+=y;
                }
                else 
                   aCount++; 
            }
            else{
                if(x>y && aCount>0){
                    aCount--;
                    ans+=x;
                }
                else 
                    bCount++;
            }
        }
        ans+=min(aCount,bCount)*less;
        return ans;
    }
};