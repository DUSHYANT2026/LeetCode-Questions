class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});


        while(!pq.empty()){
            auto it  = pq.top(); pq.pop();
            int row = it.second.first; 
            int col = it.second.second;
            int dis = it.first;

            if(row == n-1 && col == m-1) return dis+1;
            vector<pair<int,int>> del = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
            for(int i=0; i<8; i++){
                int nrow = row + del[i].first;
                int ncol = col + del[i].second;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] != 1){
                    if(dist[nrow][ncol] > dis + 1){
                        dist[nrow][ncol] = dis + 1;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                } 
            }
        }
        return dist[n-1][m-1];
    }
};