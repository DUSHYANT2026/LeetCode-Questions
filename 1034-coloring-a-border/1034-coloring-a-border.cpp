class Solution {
private:
    void dfscheck(int row, int col, int n, int m, int color, vector<vector<int>> &grid, 
                  vector<vector<int>> &ans, int oldcolor, vector<vector<int>>& vis) {
        vis[row][col] = 1; 
        int count = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for (auto [it,itt] : directions) {
            int nrow = row + it;
            int ncol = col + itt;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == oldcolor){
                count++; 
                if (vis[nrow][ncol]!=1){
                    dfscheck(nrow, ncol, n, m, color, grid, ans, oldcolor, vis);
                }
            }
        }
        if (count < 4){
            ans[row][col] = color;
        }
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans = grid;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int oldcolor = grid[row][col];

        dfscheck(row, col, n, m, color, grid, ans, oldcolor, vis);

        return ans;
    }
};
