class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;

        int start = 0; int end = 0;
        for(int i=1; i<s.size(); i++){
            if(s[i-1] == s[i]){
                end++;
            }
            else{
                if((end - start) >= 2){
                    ans.push_back({start,end});
                }
                start = i;
                end = i;
            }
        }
        if(abs(start-end) >= 2) ans.push_back({start,end});
        return ans;
    }
};