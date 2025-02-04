class Solution {
private:
    void dfscheck(int row,int col,int n, int m, vector<vector<int>> &vis, vector<vector<char>> &board){
        vis[row][col] = 1;
        vector<pair<int,int>> nums = {{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0; i<4; i++){
            int nrow = row + nums[i].first;
            int ncol = col + nums[i].second;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'X'){
                dfscheck(nrow,ncol,n,m,vis,board);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int n = board.size(); int m = board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'X' && vis[i][j] != 1){
                    dfscheck(i,j,n,m,vis,board);
                    ans++;
                }
            }
        }
        return ans;
    }
};