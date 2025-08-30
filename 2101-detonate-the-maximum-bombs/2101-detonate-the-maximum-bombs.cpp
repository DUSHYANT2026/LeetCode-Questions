class Solution {
public:
    void dfscheck(int node, vector<int> &vis, vector<int> graph[], int &count){
        vis[node] = 1;
        count++;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfscheck(it, vis, graph, count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = INT_MIN;
        int n = bombs.size();
        vector<int> graph[n];

        for(int i=0; i<n; i++){
            long long x = bombs[i][0]; long long y = bombs[i][1]; long long radius = bombs[i][2];
            for(int j=0; j<n; j++){
                if(i == j) continue;
                else{
                    long long xn = abs(x-bombs[j][0]); long long yn = abs(y-bombs[j][1]);
                    if(xn*xn + yn*yn <= radius*radius) graph[i].push_back(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            vector<int> vis(n,0);
            int count = 0;
            dfscheck(i,vis,graph,count);
            ans = max(ans,count);
        }
        return ans;
    }
};