class Solution {
private:
    void dfscheck(int node, vector<int> &vis, vector<int> &path,vector<int> graph[],int &ans, int count){
        vis[node] = 1;
        path[node] = count;
        for(auto it : graph[node]){
            if(it == -1){
                path[node] = -1;
                return;
            }
            if(!vis[it]){
                dfscheck(it,vis,path,graph,ans,count+1);
            }
            else if(path[it] != -1){
                ans = max(ans,count+1-path[it]);
            }
        }
        path[node] = -1;
    } 
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> graph[n];
        for(int i=0; i<n; i++){
            graph[i].push_back(edges[i]);
        }
        vector<int> vis(n,0);
        vector<int> path(n,-1);
        int ans = -1;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfscheck(i,vis,path,graph,ans,0); 
            }
        }
        return ans;
    }
};