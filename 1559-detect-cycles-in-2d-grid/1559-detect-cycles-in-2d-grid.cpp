class Solution {
public:
    bool dfscheck(int row, int col, int prow, int pcol, int n, int m, vector<vector<int>> &vis, vector<vector<char>> & grid){
        vis[row][col] = 1;

        vector<pair<int,int>> del = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0; i<4; i++){
            int nrow = row + del[i].first;
            int ncol = col + del[i].second;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == grid[row][col]){
                if(!vis[nrow][ncol]){
                    if(dfscheck(nrow,ncol,row,col,n,m,vis,grid)) return true;
                }
                else if(vis[nrow][ncol] == 1 && nrow != prow && ncol != pcol) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    if(dfscheck(i,j,-1,-1,n,m,vis,grid)) return true;
                }
            }
        }
        return false;
    }
};