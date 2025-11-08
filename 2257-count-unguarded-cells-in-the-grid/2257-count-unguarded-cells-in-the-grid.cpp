class Solution {
public:
    vector<vector<char>> grid;
    int m, n;
    int d[5] = {0, 1, 0, -1, 0};
    void cross(int r, int c) {
        for (int a = 0; a < 4; a++) {
            int di = d[a], dj = d[a + 1];
            for (int i=r+di, j=c+dj; ; i+=di, j+=dj) {
                if (i<0 || i>=m || j<0 || j>=n || grid[i][j] == 'X') break;
                grid[i][j] = 'V';
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        this->m = m, this->n = n;
        cout<<m<<","<<n<<endl;
        grid.assign(m, vector<char>(n, ' '));
        for (auto& ij : walls)
            grid[ij[0]][ij[1]] = 'X';
        for (auto& ij : guards)
            grid[ij[0]][ij[1]] = 'X';
        for (auto& ij : guards) {
            int r = ij[0], c = ij[1];
            cross(r, c);
        }
        int cnt = 0;
        for (auto& row : grid)
            cnt += count(row.begin(), row.end(), ' ');
        return cnt;
    }
};