class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> sumX(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> sumY(n + 1, vector<int>(m + 1, 0));
        
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sumX[i + 1][j + 1] = sumX[i][j + 1] + sumX[i + 1][j] - sumX[i][j];
                sumY[i + 1][j + 1] = sumY[i][j + 1] + sumY[i + 1][j] - sumY[i][j];
                
                if (grid[i][j] == 'X') {
                    sumX[i + 1][j + 1]++;
                } else if (grid[i][j] == 'Y') {
                    sumY[i + 1][j + 1]++;
                }
                
                int x_count = sumX[i + 1][j + 1];
                int y_count = sumY[i + 1][j + 1];
                
                if (x_count > 0 && x_count == y_count) {
                    count++;
                }
            }
        }
        
        return count;
    }
};