class Solution {
public:
    void dfscheck(int node, int& ans, vector<int> &vis, vector<pair<int,int>> nums[]){
        vis[node] = 1;

        for(auto it : nums[node]){
            ans = min(ans,it.second);
            if(!vis[it.first]){
                dfscheck(it.first,ans,vis,nums);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> nums[n+1];

        for(auto it : roads){
            nums[it[0]].push_back({it[1],it[2]});
            nums[it[1]].push_back({it[0],it[2]});
        }

        vector<int> vis(n+1, 0);
        int ans = INT_MAX;
        dfscheck(1,ans,vis,nums);
        return ans;
    }
};