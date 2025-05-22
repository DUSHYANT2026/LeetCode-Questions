class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(); int m = board[0].size();

        vector<int> row = {-1,-1,0,1,1,1,0,-1};
        vector<int> col = {0,1,1,1,0,-1,-1,-1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 0;
                for(int k=0; k<8; k++){
                    int nrow = i + row[k];
                    int ncol = j + col[k];
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                        if(board[nrow][ncol] == 1 || board[nrow][ncol] == 20) count++;
                    }
                }
                if(board[i][j] == 1){
                    if(count < 2 || count > 3) board[i][j] = 20;
                }
                else{
                    if(count == 3) board[i][j] = 10; 
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 10) board[i][j] = 1;
                else if(board[i][j] == 20) board[i][j] = 0;
            }
        }
    }
};



