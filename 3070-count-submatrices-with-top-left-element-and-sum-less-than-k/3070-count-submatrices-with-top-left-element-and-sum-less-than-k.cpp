class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(); int m = grid[0].size(); 
        
        for(int i=1; i<n; i++) grid[i][0] = grid[i-1][0] + grid[i][0]; 
        for(int j=1; j<m; j++) grid[0][j] = grid[0][j-1] + grid[0][j];

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                grid[i][j] = (long long)(grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1] + grid[i][j]);
            }
        } 
        long long int count = 0;
        for(auto it : grid){
            for(auto i : it){
                if(i <= k) count++;
            }
        }
        return count;
    }
};