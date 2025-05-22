class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        // vector<vector<int>> vis(n ,vector<int> (m,0));
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        vector<vector<int>> ans(n,vector<int> (m,1e9));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        ans[0][0] = 1;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int dis = it.second;

            if(row == n-1 && col == m-1) return dis;
            vector<int> drow = {1,0,-1,0,1,-1,-1,1};
            vector<int> dcol = {0,1,0,-1,1,1,-1,-1};
            for(int i=0; i<8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0){
                    if(ans[nrow][ncol] > dis + 1){
                        ans[nrow][ncol] = dis + 1;
                        q.push({{nrow,ncol},dis+1});
                    }
                }
            }
        }
        return -1;
    }
};