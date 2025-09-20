class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> dist(n, INT_MAX);
        vector<pair<int,int>> graph[n];
        for(auto  it : edges){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0});
        vector<int> vis(n,0);
        dist[0] = 0;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis  = it[0]; 
            int node = it[1];
            if(vis[node]) continue;
            vis[node] = 1;

            for(auto i : graph[node]){
                int newnode = i.first;
                int newdis = i.second;
                if(newdis < disappear[newnode]){
                    if(dist[newnode] > dis + newdis){
                        dist[newnode] =  dis + newdis;
                        pq.push({dis+newdis,newnode});
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
           if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};