class Solution {
public:
    vector<vector<int>> rangeAddQueries(int x, vector<vector<int>>& queries) {
        
        vector<vector<int>> ans (x, vector<int> (x, 0));

        for(auto it : queries){

            int ii = it[0]; int n = it[2];
            int jj = it[1]; int m = it[3];

            for(int i=ii; i<=n; i++){
                for(int j=jj; j<=m; j++){

                    cout<<ans[i][j] + 1<<endl;
                    ans[i][j] = ans[i][j] + 1;

                }
            }

        }
        return ans;
    }
};