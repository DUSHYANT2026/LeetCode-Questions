// class Solution {
// public:
//     int bfscheck(int node,vector<int> &vis, vector<int> graph[]){      
//         queue<int> q;
//         q.push(node);
//         int total = 0;
//         int level = 0;
//         vis[node] = 1;

//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0; i<size; i++){
//                 auto it = q.front(); q.pop();
//                 vis[it] = 1;
//                 total += level;
//                 for(auto i : graph[it]){
//                     if(!vis[i]){
//                         q.push(i);
//                     }
//                 }
//             }
//             level++;
//         }
//         return total;
//     }
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<int> graph[n];

//         for(auto it : edges){
//             graph[it[0]].push_back(it[1]);
//             graph[it[1]].push_back(it[0]);
//         }

//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             vector<int> vis(n, 0);
//             ans.push_back(bfscheck(i,vis,graph));
//         }
//         return ans;
//     }
// };



class Solution {
    vector<int> ans, count;
    vector<vector<int>> adj;
    int N;
public:
    void dfs1(int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u);
            count[u] += count[v];
            ans[u] += ans[v] + count[v];
        }
    }
    void dfs2(int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;
            ans[v] = ans[u] - count[v] + (N - count[v]);   // re rooting using dp
            dfs2(v, u);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        adj.resize(n);
        ans.assign(n, 0);
        count.assign(n, 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs1(0, -1); 
        dfs2(0, -1); 
        
        return ans;
    }
};