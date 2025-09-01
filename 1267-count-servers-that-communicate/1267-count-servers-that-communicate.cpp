class Solution {
public:
    // void dfscheck(int row, int col, int n, int m,long long& sum, vector<vector<int>> &vis, vector<vector<int>> &grid){
    //     vis[row][col] = 1; 
    //     sum += grid[row][col];
    //     vector<pair<int,int>> del = {{1,0},{-1,0},{0,1},{0,-1}};
    //     for(int i=0; i<4; i++){
    //         int nrow = row + del[i].first;
    //         int ncol = col + del[i].second;
    //         if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] != 0){
    //             dfscheck(nrow,ncol,n,m,sum,vis,grid);
    //         }
    //     }
    // }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        // int count = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         long long sum = 0;
        //         if(!vis[i][j] && grid[i][j] != 0){
        //             dfscheck(i,j,n,m,sum,vis,grid);
        //             cout<<sum<<endl;
        //             if(sum != 1) count += sum;
        //         }
        //     }
        // }
        // return count;
        vector<int> row (n, 0);
        vector<int> col (m, 0);

        for(int i=0;  i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        } 
        for(auto it : row) cout<<it<<" ";
        cout<<endl;
        for(auto it : col) cout<<it<<" ";

        int count = 0;

        for(int i=0; i<n;  i++){
            for(int j=0; j<m ; j++){
                if(grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)){
                    count++;
                }
            }
        }

        return count;

    }
};