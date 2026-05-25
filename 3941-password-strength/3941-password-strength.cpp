class Solution {
public:
    int passwordStrength(string password) {
       set<char> s;
       for(auto it : password) s.insert(it);
       int ans = 0;
       for(auto it : s){
    
        if(it >= 'a' && it <= 'z'){ cout<<it<<" "; ans += 1; } 
        else if(it >= 'A' && it <= 'Z'){  cout<<it<<" "; ans += 2; }
        else if(it-'0' >= 0 && it-'0' <= 9){  cout<<it<<" "; ans += 3; }
        else ans += 5; 
       } 
       return ans;
    }
};