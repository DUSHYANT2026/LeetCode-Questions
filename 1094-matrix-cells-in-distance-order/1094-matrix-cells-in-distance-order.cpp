class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                ans.push_back({i,j,abs(rCenter-i)+abs(cCenter-j)});
            }
        }
        auto coustom = [](vector<int> &a , vector<int> &b){
            return a[2] < b[2];
        };
        sort(ans.begin(),ans.end(),coustom);
        vector<vector<int>> newans;
        for(auto it : ans) newans.push_back({it[0],it[1]});
        return newans;
    }
};