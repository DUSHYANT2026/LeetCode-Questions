class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int layers = min(n, m) / 2;

        int rs = 0, re = n - 1;
        int cs = 0, ce = m - 1;

        while(layers--) {
            vector<int> v;

            for (int j = cs; j <= ce; j++) v.push_back(grid[rs][j]);
            for (int i = rs + 1; i <= re; i++) v.push_back(grid[i][ce]);
            for (int j = ce - 1; j >= cs; j--) v.push_back(grid[re][j]);
            for (int i = re - 1; i > rs; i--) v.push_back(grid[i][cs]);

            int len = v.size();
            int rot = k % len;
            
            if (rot > 0) {
                reverse(v.begin(), v.begin() + rot);
                reverse(v.begin() + rot, v.end());
                reverse(v.begin(), v.end());
            }

            int idx = 0;
            for (int j = cs; j <= ce; j++) grid[rs][j] = v[idx++];
            for (int i = rs + 1; i <= re; i++) grid[i][ce] = v[idx++];
            for (int j = ce - 1; j >= cs; j--) grid[re][j] = v[idx++];
            for (int i = re - 1; i > rs; i--) grid[i][cs] = v[idx++];

            rs++; re--; cs++; ce--;
        }

        return grid;
    }
};