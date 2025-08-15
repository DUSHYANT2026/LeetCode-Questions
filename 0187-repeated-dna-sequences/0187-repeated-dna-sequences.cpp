class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> mapp;

        for(int i=0; i<s.size()-9; i++){
            mapp[s.substr(i,10)]++;
        }
        for(auto it : mapp){
            if(it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};