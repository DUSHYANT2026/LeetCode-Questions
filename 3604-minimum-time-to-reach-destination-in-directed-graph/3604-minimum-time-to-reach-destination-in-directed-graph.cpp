class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph[n];

        for(auto it : edges){
            graph[it[0]].push_back({it[1],it[2],it[3]});
        }
        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        vector<int> vis(n, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto  it = pq.top(); pq.pop();
            int node = it[1];
            int time = it[0];

            if(node == n-1) return time;

            if(vis[node] == 1) continue;
            vis[node] = 1;

            for(auto i : graph[node]){
                int newn = i[0];
                int start = i[1];
                int end = i[2];

                int ntime = max(start, time);
                if(ntime <= end && dist[newn] > ntime+1){
                    dist[newn] = ntime + 1; 
                    pq.push({ntime+1,newn});
                }
            }
        }
        return -1;
    }
};