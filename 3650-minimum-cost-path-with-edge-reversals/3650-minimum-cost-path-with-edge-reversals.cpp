class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> graph[n];

        for(auto it : edges){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],2*it[2]});
        }
        vector<int> dist(n,INT_MAX);
        vector<int> vis(n, 0);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        // vis[0] = 1;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it[0]; int node = it[1];

            if(vis[node] == 1) continue;
            vis[node] = 1;
            if(node == n-1) return dis;
            for(auto i : graph[node]){
                if(!vis[i.first]){
                    if(dist[i.first] > dis + i.second){
                        dist[i.first] = dis + i.second;
                        pq.push({dist[i.first],i.first});
                    }
                }
            }  
        }
        return -1;
    }
};