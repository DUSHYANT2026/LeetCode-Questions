class Solution {
private:
    void dfscheck(int node, vector<int> &vis,vector<int> graph[],int& countnode){
        vis[node] = 1;
        countnode++;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfscheck(it,vis,graph,countnode);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> vis (n,0);
        long long pairs = ((long long)n*(n-1))/2;
        long long realpairs = 0;
        for(int i=0; i<n; i++){
            int nodes_in_components = 0;
            if(!vis[i]){
                dfscheck(i,vis,graph,nodes_in_components);
                realpairs += (nodes_in_components*(nodes_in_components-1))/2;
            }
        }
        return pairs - realpairs;
    }
};