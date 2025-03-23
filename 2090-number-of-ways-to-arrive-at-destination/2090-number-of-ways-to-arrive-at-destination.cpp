class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,
        greater<pair<long long ,long long>>> pq;
        pq.push({0,0});
        vector<long long> dist(n,LONG_MAX) ,way(n,0);
        dist[0]=0;
        way[0]=1;
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            long long dis=it.first;
            long long node=it.second;
            
            for(auto it: adj[node]){
                long long adjnode=it.first;
                long long weight=it.second;
                if(dis+weight<dist[adjnode]){
                    dist[adjnode] =dis+weight;
                    pq.push({dist[adjnode],adjnode});
                    way[adjnode]=way[node];
                }
                else if(dis+weight==dist[adjnode]){
                    way[adjnode]=(way[adjnode]+way[node])%mod;
                }
            }
        }
        return way[n-1]%mod;
    }
};
