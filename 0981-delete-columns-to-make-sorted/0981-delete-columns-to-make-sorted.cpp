class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int count = 0;
        for(int i=0; i<str[0].size(); i++){
            for(int j=1; j<str.size(); j++){
                if(str[j-1][i] > str[j][i]){
                    count++; break;
                }
            }
        }
        return count;
    }
};