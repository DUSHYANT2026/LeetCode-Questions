class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(); int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        int row = 0; int col = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    row = i;
                    col = j;
                    q.push({0,{row,col}});
                }
            }
        }
        int check = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) check++;
            }
        }
        if(check == 0) return 0;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int xrow = it.second.first;
            int xcol = it.second.second;
            int timer = it.first;
            ans = max(ans,timer);
            vector<int> drow = {1,0,-1,0};
            vector<int> dcol = {0,1,0,-1};
            for(int i=0; i<4; i++){
                int nrow = xrow + drow[i];
                int ncol = xcol + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({timer+1,{nrow,ncol}});
                }
            } 
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};