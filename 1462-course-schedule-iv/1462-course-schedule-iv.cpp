class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        
        for(auto it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        for(auto it : prerequisites){
            degree[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        
        vector<unordered_set<int>> mapp(numCourses);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node]){
                mapp[it].insert(node);
                for(auto i : mapp[node]){
                    mapp[it].insert(i);
                }
                degree[it]--;
                if(degree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        for(auto it : queries){
            if(mapp[it[1]].find(it[0]) != mapp[it[1]].end()){
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
