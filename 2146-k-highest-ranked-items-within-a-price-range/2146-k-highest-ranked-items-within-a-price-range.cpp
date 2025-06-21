// class Solution {
// public:
//     vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
//         vector<vector<int>> ans;
//         int n = grid.size(); int m = grid[0].size();
//         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
//         pq.push({0,{start[0],start[1]}});
    
//         vector<vector<int>> vis (n, vector<int> (m,0));
//         vector<pair<int,pair<int,int>>> v;
//         while(!pq.empty()){
//             auto it = pq.top(); pq.pop();
//             int row = it.second.first;
//             int col = it.second.second;
//             int weight = it.first;

//             vis[row][col] = 1;

//             vector<pair<int,int>> nums = {{1,0},{0,1},{-1,0},{0,-1}};
//             for(int i=0; i<4; i++){
//                 int nrow = row + nums[i].first;
//                 int ncol = col + nums[i].second;
//                 if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] != 0){
//                     if(grid[nrow][ncol] == 1) continue;
//                     if(pricing[0] <= grid[nrow][ncol] && pricing[1] >= grid[nrow][ncol]){
//                         int rank = nrow + ncol + grid[nrow][ncol] + weight;
//                         pq.push({rank,{nrow,ncol}});
//                         v.push_back({rank,{nrow,ncol}});
//                     }
//                 }
//             }
//         }
//         sort(v.rbegin(),v.rend());
//         for(int i=0; i<k; i++){
//             ans.push_back({v[i].second.first,v[i].second.second});
//         }
//         return ans;
//     }
// };




class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> ans;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<vector<int>> q; 
        
        int startRow = start[0], startCol = start[1];
        if (grid[startRow][startCol] >= pricing[0] && grid[startRow][startCol] <= pricing[1]) {
            ans.push_back({startRow, startCol});
        }
        
        q.push({0, grid[startRow][startCol], startRow, startCol});
        vis[startRow][startCol] = 1;
        
        vector<vector<int>> candidates;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int dist = curr[0], price = curr[1], row = curr[2], col = curr[3];
            
            for (auto& dir : dirs) {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] != 0 && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    int newPrice = grid[newRow][newCol];
                    if (newPrice >= pricing[0] && newPrice <= pricing[1]) {
                        candidates.push_back({dist + 1, newPrice, newRow, newCol});
                    }
                    q.push({dist + 1, newPrice, newRow, newCol});
                }
            }
        }
        sort(candidates.begin(), candidates.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0]; 
            if (a[1] != b[1]) return a[1] < b[1]; 
            if (a[2] != b[2]) return a[2] < b[2]; 
            return a[3] < b[3];                   
        });
        
        for (int i = 0; i < min(k, (int)candidates.size()); i++) {
            ans.push_back({candidates[i][2], candidates[i][3]});
        }
        return ans;
    }
};