class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(); int m = grid[0].size(); 
        vector<vector<int>> dp (n, vector<int> (m,0));

        long long int sum = 0;
        for(int i=0; i<n; i++){
            sum += grid[i][0];
            grid[i][0] = sum;
        }
        long long int sum2 = 0;
        for(int j=0; j<m; j++) {
            sum2 += grid[0][j];
            grid[0][j] = sum2;
        }

        for(int i=1; i<n; i++){
            long long int sum = 0;
            for(int j=1; j<m; j++){
                grid[i][j] = grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1] + grid[i][j];
            }
        } 
        long long int count = 0;
        for(auto it : grid){
            for(auto i : it){
                if(i <= k) count++;
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return count;
    }
};