class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int> (m,INT_MAX));
        distance[0][0] = 0;

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it.first;
            int row = it.second.first; int col = it.second.second;

            if(row == n-1 && col == m-1) return dis;

            for(int i=0; i<4; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    int newmove = ((nrow+ncol)%2 == 0) ? 2:1; 
                    int newdis = max(dis,grid[nrow][ncol])+newmove; 
                    if(newdis < distance[nrow][ncol]){
                        distance[nrow][ncol] = newdis;
                        pq.push({newdis,{nrow,ncol}});
                    } 
                }
            }
        }
        return distance[n-1][m-1];
    }
};

