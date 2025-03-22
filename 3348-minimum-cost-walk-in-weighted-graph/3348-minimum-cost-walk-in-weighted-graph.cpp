class Solution {
public:
    int solve(int start,vector<vector<pair<int,int>>>&adj,vector<bool>&vis,vector<int>&com,int id){
        queue<int>q;
        int cost=INT_MAX;
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            com[node]=id;
            for(auto it:adj[node]){
                cost&=it.second;
                if(vis[it.first])
                    continue;
                vis[it.first]=true;
                q.push(it.first);
            }
        }
        return cost;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<bool>vis(n,false);
        vector<int>com(n);
        vector<int>cost;
        int id=0;
        for(int node=0;node<n;node++){
            if(!vis[node]){
                cost.push_back(solve(node,adj,vis,com,id));
                id++;
            }
        }
        vector<int>ans;
        for(auto it:query){
            int start=it[0];
            int end=it[1];
            if(com[start]==com[end])
                ans.push_back(cost[com[start]]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};