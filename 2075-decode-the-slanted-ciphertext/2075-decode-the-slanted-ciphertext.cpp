class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int m = rows;
        int n = (s.length()/rows);
        vector<vector<char>> vc(m,vector<char>(n));
        int ind = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<n;j++){
                vc[i][j]=s[j+ind];
            }
            ind+=n;
        } 
        string ans = "";
        for(int j=0;j<n;j++){
            int starti = 0;
            int startj = j;
            while(starti<m && startj<n){
                ans+=vc[starti][startj];
                starti++;
                startj++;
            }
        }
        while(ans.back()==' ') ans.pop_back();
        if(s.empty()) return "";
        return ans;
    }
};