class Solution {
public:
    void recurcheck(int i, int n, vector<int> &temp, vector<int>& v, vector<vector<int>> &subset){
        if(i == n){
            subset.push_back(temp);
            return;
        }
        if(i < n){
            temp.push_back(v[i]);
            recurcheck(i+1, n, temp, v, subset);
            temp.pop_back();
            recurcheck(i+1, n, temp, v, subset);
        }
    }
    void dfscheck(int node, vector<int> &vis, vector<int> graph[], vector<int>& nums, int& sum, vector<int> & checksub){
        vis[node] = 1;
        sum += nums[node];

        for(auto it : graph[node]){
            if(!vis[it] && checksub[it]){
                dfscheck(it, vis, graph, nums, sum, checksub);
            }
        }
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        vector<int> graph[n];
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<vector<int>> subset;
        vector<int> v;
        for(int i=0; i<n; i++) v.push_back(i);
        vector<int> temp;
        recurcheck(0, n, temp, v, subset);

        int ans = 0;
        for(auto it : subset){
            vector<int> x = it;
            int nx = x.size();
            vector<int> vis(n, 0);
            vector<int> checksub(n, 0);
            for(auto it : x){
                checksub[it]++;
            }

            int count = 0;
            int sum = 0;
            for(int i=0; i<nx; i++){
                if(!vis[x[i]]){
                    dfscheck(x[i], vis, graph, nums, sum, checksub);
                    count++;
                }
            }
            if(count == 1){
                if(sum%2 == 0) ans++;
            }
        }
        return ans;
    }
};