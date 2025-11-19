class Solution {
public:
    int check(string& s,int index, int n){
        int count = 0;
        for(int i=index; i<n; i++){
            if(s[i] == '1') count++;
        }
        return count;
    }
    int maxOperations(string s) {
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '0'){
                while(s[i+1] == '0'){
                    s.erase(s.begin()+i+1);
                }
            }
        }
        // reverse(s.begin(),s.end());
        int n = s.size();
        int ans = 0; int count = 0;
        for(int  i=0; i<n; i++){
            if(s[i] == '1') count++;
            else{
                ans += count;
            }
        }
        return ans;
    }
};