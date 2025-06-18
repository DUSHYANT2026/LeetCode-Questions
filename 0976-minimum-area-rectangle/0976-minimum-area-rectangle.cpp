class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>> mapp;
        for(auto it : points) mapp[it[0]].insert(it[1]);
        int ans = INT_MAX;

        for(auto it : points){
            for(auto i : points){
                if(it[0] == i[0] || it[1] == i[1]) continue;
                if(mapp[it[0]].count(i[1]) && mapp[i[0]].count(it[1])) {
                    int temp = abs(it[0]-i[0])*abs(it[1]-i[1]);
                    ans = min(ans,temp);
                }
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};