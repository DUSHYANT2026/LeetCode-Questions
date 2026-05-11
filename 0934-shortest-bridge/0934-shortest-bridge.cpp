class Solution {
public:
    void dfscheck(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col] = 1;
        vector<pair<int,int>> nums = {{1,0},{0,1},{-1,0},{0,-1}};
        grid[row][col] = 2;
        for(int i=0; i<4; i++){
            int nrow = row + nums[i].first;
            int ncol = col + nums[i].second;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]){
                dfscheck(nrow, ncol, n, m, vis, grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        bool mark = false;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                    dfscheck(i, j, n,  m, vis, grid); mark = true; break;
                }
            }
            if(mark == true) break;
        }
        vector<pair<int,int>> nums1, nums2;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    nums1.push_back({i,j});
                }
                else if(grid[i][j] == 2){
                    nums2.push_back({i,j});
                }
            }
        }
        int ans = INT_MAX;

        // for(auto it : nums1) cout<<it.first<<" "<<it.second<<"      ";
        // cout<<endl;
        // for(auto it : nums2) cout<<it.first<<" "<<it.second<<"      ";

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                ans = min(ans, ( abs(nums1[i].first - nums2[j].first) + abs(nums1[i].second - nums2[j].second) )  );
            }
        }
        return ans-1;
    }
};