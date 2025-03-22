class Solution {
private:
    void dfscheck(int node, int n, vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfscheck(it,n,vis,graph);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int> graph[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfscheck(i,n,vis,graph); ans++;
            }
        }
        return ans;
    }
};