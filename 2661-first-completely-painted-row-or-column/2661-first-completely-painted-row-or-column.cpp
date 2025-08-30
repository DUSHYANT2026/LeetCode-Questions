class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int n = mat.size(); int m = mat[0].size();

        unordered_map<int,pair<int,int>>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>rcnt(n,0);
        vector<int>ccnt(m,0);
        for(int i=0;i<arr.size();i++){
            int row=mp[arr[i]].first;
            int col=mp[arr[i]].second;
            rcnt[row]++;
            ccnt[col]++;
            if(rcnt[row]==m||ccnt[col]==n)return i;
        }
        return 0;
    }
};