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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> graph[n];
        for(int i=0; i<n; i++){
            for(auto it : rooms[i]){
                graph[i].push_back(it);
            }
        }
        vector<int> vis(n, 0);

        dfscheck(0,vis,graph);

        for(auto it : vis){
            if(it == 0) return false;
        }
        return true;
    }
};