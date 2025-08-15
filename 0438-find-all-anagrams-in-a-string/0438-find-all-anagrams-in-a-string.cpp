class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        int size = p.size();
        sort(p.begin(),p.end());
        vector<int> ans;

        for(int i=0; i<s.size()-size+1; i++){
            string temp = s.substr(i,size);
            sort(temp.begin(),temp.end());
            if(temp == p){
                ans.push_back(i);
            }
        }
        return ans;
    }
};