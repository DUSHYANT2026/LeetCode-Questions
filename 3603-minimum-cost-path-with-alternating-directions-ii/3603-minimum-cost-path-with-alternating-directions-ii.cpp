class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(2, LLONG_MAX)));
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        
        pq.push({1, 0, 0, 1});
        dist[0][0][1] = 1;
        
        vector<pair<int,int>> directions = {{1,0}, {0,1}};
        
        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();
            
            long long cost = current[0];
            int row = current[1];
            int col = current[2];
            int time = current[3];
            
            if(row == n-1 && col == m-1) {
                return cost;
            }
            
            if(cost > dist[row][col][time % 2]) {
                continue;
            }
            
            if(time % 2 == 1) {
                for(auto& dir : directions){
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;
                    
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                        long long newCost = cost + (nrow + 1) * (ncol + 1);
                        
                        if(newCost < dist[nrow][ncol][0]){
                            dist[nrow][ncol][0] = newCost;
                            pq.push({newCost, nrow, ncol, time + 1});
                        }
                    }
                }
            } else {
                long long newCost = cost + waitCost[row][col];
                
                if(newCost < dist[row][col][1]){
                    dist[row][col][1] = newCost;
                    pq.push({newCost, row, col, time + 1});
                }
            }
        }
        
        return -1;
    }
};