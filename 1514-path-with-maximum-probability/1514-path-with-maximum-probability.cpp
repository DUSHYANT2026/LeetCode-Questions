class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> ans(n,0);
        vector<pair<int,double>> graph[n];
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});   
        }
        priority_queue<pair<double,int>> pq;

        pq.push({1,start_node});
        ans[start_node] = 0;
        vector<int> vis(n, 0);
        
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            auto node = it.second;
            double dis = it.first;
            if(node == end_node) return dis;

            if(vis[node] == 1) continue;
            vis[node] = 1;
            
            for(auto i : graph[node]){
                auto x = i.first; 
                double y = i.second;
                if(ans[x] < y * dis){
                    ans[x] = y * dis;
                    pq.push({ans[x],x});
                }
            }
        }
        return double();
    }
};