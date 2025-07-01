class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string x = "qwertyuiop", y = "asdfghjkl", z = "zxcvbnm";
        unordered_map<char,int> mapp;
        for(auto it : x){
            mapp[it] = 1;
        }
        for(auto it : y){
            mapp[it] = 2;
        }
        for(auto it : z){
            mapp[it] = 3;
        }
        for(int i=0; i<words.size(); i++){
            int j;
            for(j=1; j<words[i].size(); j++){
                if(mapp[tolower(words[i][j])] != mapp[tolower(words[i][j-1])]){
                    break;}
            }
            if(j == words[i].size()){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
