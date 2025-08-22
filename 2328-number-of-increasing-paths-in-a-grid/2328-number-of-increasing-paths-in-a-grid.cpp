class Solution {
public:
    int mod = 1000000007;
    
    int dpcheck(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(dp[i][j] != -1) return dp[i][j];
        
        vector<pair<int,int>> del = {{1,0},{-1,0},{0,-1},{0,1}};
        
        long long temp = 1; 
        for(int k = 0; k < 4; k++){
            int ni = i + del[k].first;
            int nj = j + del[k].second;
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[i][j] < grid[ni][nj]){
                temp = (temp + dpcheck(ni, nj, n, m, dp, grid)) % mod;
            }
        }
        
        return dp[i][j] = temp % mod;
    }
    
    int countPaths(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        
        long long ans = 0; 
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = (ans + dpcheck(i, j, n, m, dp, matrix)) % mod;
            }
        }
        
        return ans % mod;
    }
};