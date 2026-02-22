class Solution {
public:
    string convert(int n){
        string ans = "";
        while(n != 0){
            ans = to_string(n%2) + ans;
            n = n/2; 
        }
        return ans;
    }
    int binaryGap(int n) {
        string s = convert(n);
        int ans = 0;

        int x = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') {x = i; break;}
        }
        int j = x;
        if(x <= s.size()){
            for(int i=x+1; i<s.size(); i++){
                if(s[i] == '1'){
                    ans = max(ans, i-j);
                    j = i;
                }
            }
        }
        return ans;
    }
};