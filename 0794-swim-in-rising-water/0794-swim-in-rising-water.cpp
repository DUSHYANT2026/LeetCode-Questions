class Solution {
public:
    int swimInWater(vector<vector<int>>& nums) {
        int n = nums.size(); int m = nums[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({nums[0][0],{0,0}});
        vis[0][0] = 1;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;
            if(row == n-1 && col == m-1) return dis;

            vector<pair<int,int>> del = {{1,0},{0,1},{-1,0},{0,-1}};
            for(int i=0; i<4; i++){
                int nrow = row + del[i].first;
                int ncol = col + del[i].second;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 1){
                    vis[nrow][ncol] = 1;
                    pq.push({max(dis,nums[nrow][ncol]),{nrow,ncol}});
                }
            } 
        }
        return -1;
    }
};
