class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<vector<int>> ans;

        unordered_map<int,vector<int>> mapp;
        for(int i=0; i<nums.size(); i++){
            mapp[nums[i]].push_back(i);
        }
        for(auto it : mapp){
            vector<int> temp = it.second;
            int x = it.first;
            int times = temp.size()/x;
            int count = 0;
            while(times--){
                vector<int> newv;
                int nx = x;
                while(nx != 0){
                    newv.push_back(temp[count]);
                    count++;
                    nx--;
                }
                ans.push_back(newv);
            }
        }
        return ans;
    }
};