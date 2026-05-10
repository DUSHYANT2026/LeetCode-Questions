// class Solution {
// public:
//     vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
//         vector<vector<int>> nums;
//         int n = grid.size(); int m = grid[0].size();
//         int time = min(m,n)/2;
//         int ntime = min(n,m)/2;

//         int cs = 0; int ce = m-1;
//         int rs = 0; int re = n-1;
//         while(time > 0){
            
//             vector<int> v;
            
//             for(int j=cs; j<=ce; j++) v.push_back(grid[rs][j]); 
//             for(int j=rs+1; j<=re; j++) v.push_back(grid[j][ce]);  
//             for(int j=ce-1; j >= cs; j--) v.push_back(grid[re][j]);  
//             for(int j=re-1; j > rs; j--) v.push_back(grid[j][cs]);

//             cs++; rs++; ce--; re--;
//             nums.push_back(v);
//             time--;
//         }

//         vector<vector<int>> newnums;

//         for(auto it : nums){
//             int n = it.size();
//             k = k % n; 
//             reverse(it.begin(), it.begin() + k);       
//             reverse(it.begin() + k, it.end());         
//             reverse(it.begin(), it.end()); 
//             newnums.push_back(it);
//         }

//         int css = 0; int ces = m-1;
//         int rss = 0; int res = n-1;
//         int level = 0;
//         while(ntime > 0){
//             int i = 0;

//             for(int j=css; j<=ces; j++) grid[rss][j] = newnums[level][i++]; 
//             for(int j=rss+1; j<=res; j++) grid[j][ces] =  newnums[level][i++]; 
//             for(int j=ces-1; j >= css; j--) grid[res][j] = newnums[level][i++];  
//             for(int j=res-1; j > rss; j--) grid[j][css] = newnums[level][i++];


//             css++; rss++; ces--; res--;
//             level++;
//             ntime--;
//         }
        

//         return grid;

//     }
// };


class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int numLayers = min(n, m) / 2;

        int rs = 0, re = n - 1;
        int cs = 0, ce = m - 1;

        for (int layer = 0; layer < numLayers; layer++) {
            vector<int> v;

            // 1. Extract layer
            for (int j = cs; j <= ce; j++) v.push_back(grid[rs][j]);
            for (int i = rs + 1; i <= re; i++) v.push_back(grid[i][ce]);
            for (int j = ce - 1; j >= cs; j--) v.push_back(grid[re][j]);
            for (int i = re - 1; i > rs; i--) v.push_back(grid[i][cs]);

            // 2. Rotate layer
            int len = v.size();
            int rot = k % len; // Use a local 'rot' so we don't destroy 'k'
            if (rot > 0) {
                // To rotate anti-clockwise by 'rot', 
                // the element at index 'rot' moves to index 0.
                reverse(v.begin(), v.begin() + rot);
                reverse(v.begin() + rot, v.end());
                reverse(v.begin(), v.end());
            }

            // 3. Put back into grid
            int idx = 0;
            for (int j = cs; j <= ce; j++) grid[rs][j] = v[idx++];
            for (int i = rs + 1; i <= re; i++) grid[i][ce] = v[idx++];
            for (int j = ce - 1; j >= cs; j--) grid[re][j] = v[idx++];
            for (int i = re - 1; i > rs; i--) grid[i][cs] = v[idx++];

            // 4. Shrink boundaries
            rs++; re--; cs++; ce--;
        }

        return grid;
    }
};