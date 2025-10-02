class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,vector<int>> mapp;
        for(auto it : pick){
            mapp[it[0]].push_back(it[1]);
        } 
        int count = 0;
        for(auto it : mapp){
            unordered_map<int,int> temp; int maxi = 0;
            for(auto i : it.second) temp[i]++;
            for(auto x : temp) maxi = max(maxi,x.second);
            if(it.first < maxi) count++;
        }
        return count;
    }
};