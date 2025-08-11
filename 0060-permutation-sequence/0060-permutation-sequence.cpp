class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i=1; i<=n; i++){ s += to_string(i); }
    
        int count = 1;
    
        string ans = "";
    
        do{ 
            if(count == k){
               ans = s;
               break;
            }
            count++;
        }while(next_permutation(s.begin(),s.end()));

        return ans;
    }
};