class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mapp;
        for(int i = 0; i < nums.size(); i++){
            mapp[nums[i]].push_back(i);
        }

        int n = queries.size();
        vector<int> ans;

        for(auto i : queries){
            int it = nums[i];
            if(mapp.find(it) == mapp.end() || mapp[it].size() == 1) ans.push_back(-1);
            else{
                vector<int>& v = mapp[it];
                auto itt = lower_bound(v.begin(), v.end(), i);
                if(itt != v.end()){
                    int index = itt - v.begin();
                    if(index != 0 && index != (int)v.size()-1){
                        ans.push_back(min((v[index] - v[index-1]), (v[index+1] - v[index])));
                    }
                    else {
                        if(index == 0){
                            int x = (nums.size() - v[v.size()-1]) + v[0];
                            ans.push_back(min((v[1] - v[0]), x));
                        }
                        else{
                            int x = (nums.size() - v[v.size()-1]) + v[0];
                            ans.push_back(min((v[v.size()-1] - v[v.size()-2]), x));
                        }    
                    }
                }
            }
        }
        return ans;
    }
};