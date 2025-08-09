class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mapp;
        int count = 0;
        for(auto it : grid){
            vector<int> temp;
            for(auto i : it){
                temp.push_back(i);
            }
            mapp[temp]++;
        }
        for(int i=0; i<grid[0].size(); i++){
            vector<int> temp;
            for(int j=0; j<grid.size(); j++){
                temp.push_back(grid[j][i]);
            }
            if(mapp.find(temp) != mapp.end()){
                count += mapp[temp];
            }
        }
        return count;
    }
};