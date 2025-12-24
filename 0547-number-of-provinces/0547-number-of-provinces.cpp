class Solution {
public:
    void dfscheck(int node, vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfscheck(it,vis,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size(); int m = nums[0].size();
        vector<int> graph[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i != j && nums[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfscheck(i,vis,graph); ans++;
            }
        }
        return ans;
    }
};