class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string,int> mp;
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string x=words[i];
            sort(x.begin(),x.end());
            if(mp[x] == 0){
                if(mp.size()!=0){
                    mp.clear();
                }
                ans.push_back(words[i]);
                mp[x]++;
            }      
        }
        return ans;
    }
};


