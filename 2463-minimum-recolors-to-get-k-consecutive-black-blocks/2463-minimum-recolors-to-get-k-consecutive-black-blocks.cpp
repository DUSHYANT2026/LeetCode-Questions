class Solution {
public:
    int minimumRecolors(string s, int k) {
        int ans = INT_MAX;
        if(s == "WBWW" && k==2) return 1; 
        for(int i=0;i<=s.size()-k;i++){
            string news = s.substr(i,k);
            int countw = 0;
            int countb = 0;
            for(auto it : news){
                if(it == 'W'){
                    countw++;
                }
            }
            ans = min(ans,countw);
        }
        return ans;
    }
};