// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& nums) {
//         unordered_map<int, set<int>> mapp1, mapp2;
//         for(auto it : nums){
//             mapp1[it[0]].insert(it[1]);
//             mapp2[it[1]].insert(it[0]);
//         }
//         int ans = 0;
//         for(auto it : nums){
//             auto x = mapp1[it[0]]; auto y = mapp2[it[1]];
//             if(!x.empty() && !y.empty())
//             if((it[0] > *x.begin() && it[0] < *x.rbegin()) && (it[1] > *y.begin() && it[1] < *y.rbegin())){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // mapp1 stores X -> {set of Y coordinates}
        unordered_map<int, set<int>> mapp1;
        // mapp2 stores Y -> {set of X coordinates}
        unordered_map<int, set<int>> mapp2;
        
        for(auto& it : buildings){
            mapp1[it[0]].insert(it[1]);
            mapp2[it[1]].insert(it[0]);
        }
        
        int ans = 0;
        for(auto& it : buildings){
            int curX = it[0];
            int curY = it[1];
            
            // Use auto& to avoid copying the set (Performance Fix)
            auto& y_set = mapp1[curX]; 
            auto& x_set = mapp2[curY];
            
            // Logic Fix: 
            // Check if curY is strictly between min Y and max Y for this X
            bool coveredByY = (curY > *y_set.begin() && curY < *y_set.rbegin());
            
            // Check if curX is strictly between min X and max X for this Y
            bool coveredByX = (curX > *x_set.begin() && curX < *x_set.rbegin());
            
            if(coveredByY && coveredByX){
                ans++;
            }
        }
        return ans;
    }
};