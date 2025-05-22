class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        unordered_map<int,int> mapp;
        for(int i=0; i<limits.size(); i++) mapp[i] = limits[i];

        priority_queue<pair<int,int>> pq;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                pq.push({grid[i][j],i});
            }
        }
        long long ans = 0;
        while(k > 0 && !pq.empty()){
            auto it = pq.top(); pq.pop();
            if(mapp[it.second] > 0){
                ans += it.first;
                mapp[it.second]--;
                k--;
            }
        }
        return ans;
    }
};