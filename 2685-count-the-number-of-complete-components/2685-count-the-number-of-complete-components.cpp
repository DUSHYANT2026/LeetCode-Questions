class Solution {
private: 
    void dfscheck(int node,vector<int> &vis,vector<int> adj[],int &nodecount,int &edgecount){
        vis[node] = 1; 
        nodecount++;
        for(auto it : adj[node]){
            edgecount++;
            if(!vis[it]){
                dfscheck(it,vis,adj,nodecount,edgecount);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto  it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            int nodecount = 0; int edgecount=0;
            if(!vis[i]){
                dfscheck(i,vis,adj,nodecount,edgecount);
                if(nodecount*(nodecount-1) == edgecount) count++;
            }
        }
        return count;
    }
};