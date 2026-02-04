class Solution {
public:
    bool check1(int row, vector<vector<int>> &mat){
        int sum  = 0;
        for(int j=0; j<mat[0].size(); j++){
            sum += mat[row][j];
        }
        return sum==1;
    }
    bool check2(int col, vector<vector<int>> &mat){
        int sum  = 0;
        for(int i=0; i<mat.size(); i++){
            sum += mat[i][col];
        }
        return sum==1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1 && check1(i,mat) && check2(j,mat)){
                   count++;
                }
            }
        } 
       return count;
    }
};