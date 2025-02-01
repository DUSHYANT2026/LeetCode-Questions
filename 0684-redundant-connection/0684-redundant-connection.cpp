class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj,
             vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                
                if (low[it] > tin[node]) {
                    bridges.push_back({it + 1, node + 1});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            int u = it[0] - 1, v = it[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0), tin(n, -1), low(n, -1);
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> bridges = criticalConnections(n, edges);
        
        for (int i = n - 1; i >= 0; i--) {
            bool flag = false;
            for (int j = 0; j < bridges.size(); j++) {
                if ((edges[i][0] == bridges[j][0] && edges[i][1] == bridges[j][1]) ||
                    (edges[i][0] == bridges[j][1] && edges[i][1] == bridges[j][0])) {
                    flag = true;
                    break;
                }
            }
            if (!flag) return edges[i];
        }
        return {};
    }
};