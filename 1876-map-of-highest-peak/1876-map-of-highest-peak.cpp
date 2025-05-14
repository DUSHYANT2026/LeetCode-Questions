class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<int>> ans(n,vector<int> (m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int row = it.second.first;
            int col = it.second.second;
            int dist = it.first;
            ans[row][col] = dist;
            vector<int> drow = {+1,0,-1,0};
            vector<int> dcol = {0,+1,0,-1};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 1 ){
                    vis[nrow][ncol] = 1;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
        return ans;
    }
};