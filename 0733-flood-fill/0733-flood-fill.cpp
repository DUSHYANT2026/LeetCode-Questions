class Solution {
private:
    void dfscheck(int n,int m,vector<vector<int>>& image, vector<vector<int>>& ans,int sr,int sc,int color,int initialcolor){
        ans[sr][sc] = color;

        int delrow[] = {0,+1,0,-1};
        int delcol[] = {+1,0,-1,0};

        for(int i=0;i<4;i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == initialcolor
            && ans[nrow][ncol] != color){
                dfscheck(n,m,image,ans,nrow,ncol,color,initialcolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        int initialcolor = image[sr][sc];
        dfscheck(n,m,image,ans,sr,sc,color,initialcolor);
        return ans;
    }
};