class Solution {
private:
    void dfscheck(int row, int col , int n, int m, vector<vector<int>>&vis , vector<vector<int>> & grid1
    , vector<vector<int>> & grid2, bool & mark){
        vis[row][col] = 1;

        if(grid1[row][col] != grid2[row][col]){
            mark = false;
        }
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid2[nrow][ncol] == 1){
                dfscheck(nrow,ncol,n,m,vis,grid1,grid2,mark);
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(); int m = grid1[0].size(); 
        vector<vector<int>> vis(n,vector<int> (m,0));

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && vis[i][j] == 0){
                    bool mark = true;
                    dfscheck(i,j,n,m,vis,grid1,grid2,mark);
                    if(mark == true){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};