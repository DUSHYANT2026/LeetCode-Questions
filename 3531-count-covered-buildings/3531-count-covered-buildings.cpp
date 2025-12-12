// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& nums) {
//         unordered_map<int, set<int>> mapp1, mapp2;
//         for(auto it : nums){
//             mapp1[it[0]].insert(it[1]);
//             mapp2[it[1]].insert(it[0]);
//         }
//         int ans = 0;
//         for(auto& it : nums){
//             auto& x = mapp1[it[1]]; auto& y = mapp2[it[0]];
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
    int countCoveredBuildings(int n, vector<vector<int>>& nums) {
        unordered_map<int, set<int>> mapp1, mapp2;
        for(auto it : nums){
            mapp1[it[0]].insert(it[1]);
            mapp2[it[1]].insert(it[0]);
        }
        
        int ans = 0;
        for(auto it : nums){
            auto &y = mapp1[it[0]]; 
            auto &x = mapp2[it[1]]; 
            
            if(!y.empty() && !x.empty())
                if((it[1] > *y.begin() && it[1] < *y.rbegin()) && 
                   (it[0] > *x.begin() && it[0] < *x.rbegin())){
                    ans++;
                }
        }
        return ans;
    }
};