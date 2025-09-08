class Solution {
public:
    bool check(int x){
        while(x != 0){
            cout<<x%10<<endl;
            if(x%10 == 0) return false;
            x = x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1; i<=n; i++){
            if(check(n-i) && check(i)) return {i,n-i};
        }
        return {};
    }
};