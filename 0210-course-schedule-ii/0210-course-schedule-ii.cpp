class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> graph[n];
        vector<int> indgree(n,0);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
        }
        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                indgree[it]++;
           }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indgree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto it = q.front(); q.pop();
            ans.push_back(it);
            for(auto i : graph[it]){
                indgree[i]--;
                if(indgree[i] == 0) q.push(i);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans.size() == n ? ans : vector<int>(); 
    }
};