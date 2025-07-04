class Solution {
public:

    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';
        long long len=1;
        long long newk=-1;
        int op=-1;
        for(int i=0; i<operations.size(); i++){
            len *= 2;
            if(len>=k){
                op= operations[i];
                newk= k-len/2;
                break;
            }
        }
        char ch= kthCharacter(newk, operations);
        if(op==0){
            return ch;
        }
        return (ch=='z')?'a':ch+1;
    }
};