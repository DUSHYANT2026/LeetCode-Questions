class Solution {
private:
    void dfscheck(int node, int& count1, int& count2, vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        count1++;
        for(auto it : graph[node]){
            count2++;
            if(!vis[it]){
                dfscheck(it,count1,count2,vis,graph);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int edge = 0; int node = 0;
                dfscheck(i,node,edge,vis,graph);
                if(edge == node*(node-1)) ans++;
            }
        }
        return ans;
    }
};