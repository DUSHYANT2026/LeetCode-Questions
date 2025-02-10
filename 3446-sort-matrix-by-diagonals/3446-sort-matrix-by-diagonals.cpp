class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        int n  = mat.size(); int m = mat[0].size();
        unordered_map<int,priority_queue<int , vector<int>, greater<int>>> pq;
        unordered_map<int,priority_queue<int>> pq1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j > i){
                    pq[j-i].push(mat[i][j]);
                }else{
                    pq1[i-j].push(mat[i][j]);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j > i){
                    mat[i][j] = pq[j-i].top();
                    pq[j-i].pop();
                }else{
                    mat[i][j] = pq1[i-j].top();
                    pq1[i-j].pop();
                }
            }
        }
        return mat;
    }
};