class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>>dist (n ,vector<int> (m,1e9));
        dist[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;

            if(row == n-1 && col == m-1) return dis;

            vector<pair<int,int>> drow = {{1,0},{0,1},{-1,0},{0,-1}};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i].first;
                int ncol = col + drow[i].second;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    int ans = max(dis,abs(grid[nrow][ncol] - grid[row][col]));
                    if(dist[nrow][ncol] > ans){
                        dist[nrow][ncol] = ans;
                        pq.push({ans,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};