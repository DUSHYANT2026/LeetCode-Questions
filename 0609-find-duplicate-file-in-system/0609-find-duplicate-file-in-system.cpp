class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> nums;

        for(auto it : paths){
            stringstream ss(it);
            string temp;
            vector<string> tem;
            while(ss >> temp){
                tem.push_back(temp);
            }
            nums.push_back(tem);
        }
        unordered_map<string, vector<string>> mapp;

        for(int i=0; i<nums.size(); i++){
            vector<string> temp = nums[i];
            string s = temp[0];
            for(int j=1; j<temp.size(); j++){
                int n = temp[j].size();
                string x = temp[j].substr(0,5);
                string y = temp[j].substr(5,n);
                mapp[y].push_back(s+"/"+x);
            }
        }
        vector<vector<string>> ans;
        for(auto it : mapp){
            if(it.second.size() > 1) ans.push_back(it.second);
        }
        return ans;
    }
};