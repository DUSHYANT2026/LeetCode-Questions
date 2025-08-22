class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<int> counti, countj;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    counti.push_back(i);
                    countj.push_back(j);
                }
            }
        }
        sort(counti.begin(),counti.end());
        sort(countj.begin(),countj.end());
    

        int ans = (counti[counti.size()-1] - counti[0] +1) * (countj[countj.size()-1] - countj[0] +1) ;
        return ans;
    }
};