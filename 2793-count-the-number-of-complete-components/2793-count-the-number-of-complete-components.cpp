class Solution {
private:
    void dfscheck(int i, int& node, int& edge,  vector<int> &vis ,vector<int> graph[]){
        node++;
        vis[i]++;
        for(auto it : graph[i]){
            edge++;
            if(!vis[it]){
                dfscheck(it,node,edge,vis,graph);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& grid) {
        int ans = 0;
        vector<int> vis(n,0);
        vector<int> graph[n];
        for(auto it : grid){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++){
            int node = 0; int edge = 0;
            dfscheck(i,node,edge,vis,graph);
            if(node*(node-1) == edge) ans++;
        }
        return ans;
    }
};