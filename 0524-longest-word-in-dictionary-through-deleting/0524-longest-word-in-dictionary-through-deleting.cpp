class Solution {
public:
    string findLongestWord(string s, vector<string>& nums) {
        
        unordered_map<char, int> mapp;
        for(auto it : s) mapp[it]++;

        vector<pair<int,string>> ans;
        for(int i=0; i<nums.size(); i++){
            string temp = nums[i];
            bool mark = false;
            unordered_map<char, int> check;
           
            int index = 0;
            for(int j=0; j<s.size(); j++){
                if(s[j] == temp[index]){
                    index++;
                }
                if(index == temp.size()){
                    mark = true;
                    break;
                }
            }
            if(mark == true){
                ans.push_back({temp.size(),temp});
            }
        }
        auto custom = [](pair<int,string> &a, pair<int,string> &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        sort(ans.begin(),ans.end(),custom);
    
        return (ans.size() == 0) ? "" : ans[0].second;

    }
};