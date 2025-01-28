// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) 
//     {
//         int ans;
//         if(grid.size()==0)
//         return 0;
//         for(int i=0;i<grid.size();i++)
//         {
//             for(int j=0;j<grid[0].size();j++)
//             {
//                 if(grid[i][j]=='1')
//                 {
//                     dfs(i,j,grid);
//                     ans++;
//                 }
//             }
//         }
//         return ans-1;
//     }
//     void dfs(int i,int j,vector<vector<char>>& grid)
//     {
//         if(i<0||j<0||i>grid.size()-1||j>grid[0].size()-1)
//         return;
//         if(grid[i][j]=='0')
//         return;
//         grid[i][j]='0';
//         dfs(i+1,j,grid);
//         dfs(i-1,j,grid);
//         dfs(i,j+1,grid);
//         dfs(i,j-1,grid);
//     }
// };



// class Solution {
// private:
//     void dfscheck(int n,int m,int row,int col,vector<vector<char>>& grid){

//         int delrow[] = {1,0,-1,0};
//         int delcol[] = {0,1,0,-1};

//         for(int i=0; i<4; i++){
//             int nrow = delrow[i] + row;
//             int ncol = delcol[i] + col;

//             if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && 
//             grid[nrow][ncol] == '1'){
//                 grid[nrow][ncol] = '0'; 
//                 dfscheck(n,m,nrow,ncol,grid);
//             }
//         }
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int count = 0;
//         int n = grid.size();
//         int m = grid[0].size();

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == '1'){
//                     dfscheck(n,m,i,j,grid);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };



class Solution {
private:
    void dfscheck(int row, int col, int n, int m, vector<vector<char>> &grid, vector<vector<int>> & vis){
        vis[row][col] = 1;

        vector<pair<int,int>> del = {{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0; i<4; i++){
            int nrow = row + del[i].first;
            int ncol = col + del[i].second;
            if(nrow >= 0 && ncol < m && ncol >= 0 && nrow <n && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                dfscheck(nrow,ncol,n,m,grid,vis);
            } 
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfscheck(i,j,n,m,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
