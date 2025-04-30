class Solution {
private:
    void dfscheck(int node,vector<vector<int>>& graph,vector<int> &vis){
        vis[node] =2;
        for(auto it:graph[node]){
            if(!vis[it]){
                dfscheck(it,graph,vis);
            }
            if(vis[it] == 2) return;
        }
        vis[node]=1;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfscheck(i,graph,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i] == 1)
            ans.push_back(i);
        }
        return ans;
    }
};
