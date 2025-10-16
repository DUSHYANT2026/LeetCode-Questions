class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string,int> mapp;
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            sort(temp.begin(),temp.end());
            if(mapp[temp] == 0){
                if(mapp.size() != 0){
                    mapp.clear();
                }
                ans.push_back(words[i]);
                mapp[temp]++;
            }      
        }
        return ans;
    }
};


