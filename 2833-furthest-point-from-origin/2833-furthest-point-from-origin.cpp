class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int countl = 0;
        int countr = 0;

        for(auto it : s){
            if(it == 'L'){
                countl++;
            }
            else if(it == 'R'){
                countr++;
            }
        }
        int ans = 0;
        if(countl == countr){
            for(auto it : s){
                if(it == '_') ans++;
            }
            return ans;
        }
        
        if(countl > countr){
            for(int i=0;i<s.size();i++){
                if(s[i] == '_'){
                    s[i] = 'L';
                }
            }
        }
        else{
            for(int i=0;i<s.size();i++){
                if(s[i] == '_'){
                    s[i] = 'R';
                }
            }
        }
        int newans = 0;
        for(auto it : s){
            if(it == 'L'){
                newans++;
            }else{
                newans--;
            }
        }
        return abs(newans);
    }
};