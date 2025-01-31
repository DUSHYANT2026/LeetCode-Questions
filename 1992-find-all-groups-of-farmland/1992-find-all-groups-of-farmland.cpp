class Solution {
private:
    void dfscheck(int row,int col, int n, int m, int &x, int &y, vector<vector<int>> & vis , vector<vector<int>> &land){
        vis[row][col] = 1;
        vector<pair<int,int>> nums = {{-1,0},{0,1},{1,0},{0,-1}};

        x = max(row,x);
        y = max(col,y);
        for(int i=0; i<4; i++){
            int nrow = nums[i].first + row;
            int ncol = nums[i].second + col;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && land[nrow][ncol] == 1){
                dfscheck(nrow,ncol,n,m,x,y,vis,land);
            }
        }

    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        int n = land.size(); int m = land[0].size(); 
        vector<vector<int>> vis (n, vector<int> (m,0));


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 && vis[i][j] == 0){
                    int x = i, y = j;
                    dfscheck(i,j,n,m,x,y,vis,land);
                    ans.push_back({i,j,x,y});
                }
            }
        }
        return ans;
    }
};



// class Solution {
// private:
//     void dfscheck(int row, int col, int n, int m, int &x, int &y, vector<vector<int>> &vis, vector<vector<int>> &land) {
//         vis[row][col] = 1;
//         x = max(row, x); 
//         y = max(col, y); 

//         vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
//         for (auto [dx, dy] : directions) {
//             int nrow = row + dx;
//             int ncol = col + dy;
//             if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && land[nrow][ncol] == 1) {
//                 dfscheck(nrow, ncol, n, m, x, y, vis, land);
//             }
//         }
//     }

// public:
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         vector<vector<int>> ans;
//         int n = land.size(), m = land[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (land[i][j] == 1 && !vis[i][j]) {
//                     int x = i, y = j;
//                     dfscheck(i, j, n, m, x, y, vis, land);
//                     ans.push_back({i, j, x, y});
//                 }
//             }
//         }
//         return ans;
//     }
// };
