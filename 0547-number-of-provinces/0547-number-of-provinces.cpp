class Solution {
private:
    void dfscheck(int node,vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfscheck(it,vis,graph);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n = isconnected.size();
        vector<int> graph[n+1];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isconnected[i][j] == 1){
                    if(i != j){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfscheck(i,vis,graph);
                ans++;
            }
        }
        return ans;
    }
};