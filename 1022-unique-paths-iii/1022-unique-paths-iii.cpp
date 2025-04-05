class Solution {
private:
    int dpsolve(int i, int j, int x, int y, int n, int m, int count, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (i == x && j == y) {
            return count == 0 ? 1 : 0;
        }
        
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1 || visited[i][j]) {
            return 0;
        }
        
        visited[i][j] = true;
        int paths = 0;
        
        paths += dpsolve(i + 1, j, x, y, n, m, count - 1, grid, visited);
        paths += dpsolve(i - 1, j, x, y, n, m, count - 1, grid, visited);
        paths += dpsolve(i, j + 1, x, y, n, m, count - 1, grid, visited);
        paths += dpsolve(i, j - 1, x, y, n, m, count - 1, grid, visited);
        
        visited[i][j] = false; // Backtrack
        return paths;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int start_i = 0, start_j = 0, end_i = 0, end_j = 0;
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                    count++;
                } else if (grid[i][j] == 2) {
                    end_i = i;
                    end_j = j;
                    count++;
                } else if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return dpsolve(start_i, start_j, end_i, end_j, n, m, count - 1, grid, visited);
    }
};