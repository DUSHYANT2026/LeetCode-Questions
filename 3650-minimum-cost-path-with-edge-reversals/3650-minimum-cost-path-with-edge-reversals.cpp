// class Solution {
// private:
//     void dfscheck(int node, vector<int> &vis, stack<int> & s, vector<pair<int,int>> graph[]){
//         vis[node] = 1;
//         for(auto i : graph[node]){
//             if(!vis[i.first]){
//                 dfscheck(i.first,vis,s,graph);
//             }
//         }
//         s.push(node);
//     }
// public:
//     int minCost(int n, vector<vector<int>>& edges) {
        
//         vector<pair<int,int>> graph[n];

//         for(auto it : edges){
//             graph[it[0]].push_back({it[1],it[2]});
//             graph[it[1]].push_back({it[0],2*it[2]});
//         }
//         vector<int> vis(n, 0);
//         stack<int> s;

//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 dfscheck(i,vis,s,graph);
//             }
//         }
//         vector<int> dist(n, 1e9);
//         dist[0] = 0;

//         while(!s.empty()){
//             auto it = s.top(); s.pop();
//             if(dist[it] != 1e9){
//                 for(auto i : graph[it]){
//                     if(dist[i.first] > i.second + dist[it]){
//                         dist[i.first] = i.second + dist[it];
//                     }
//                 }
//             }
//         }
//         return (dist[n-1] == 1e9) ? -1 : dist[n-1];
//     }
// };











class Solution {

public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> nums[n];
        for(auto it : edges){
            nums[it[0]].push_back({it[1],it[2]});
            nums[it[1]].push_back({it[0],2*it[2]});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it.first;
            int node = it.second;

            if(node == n-1) return dis;
            for(auto i : nums[node]){
                int newn = i.first;
                int ndis = i.second;
                if(dist[newn] > ndis + dis){
                    dist[newn] = ndis + dis;
                    pq.push({dist[newn], newn});
                }
            }
        }
        return -1;
    }
};


