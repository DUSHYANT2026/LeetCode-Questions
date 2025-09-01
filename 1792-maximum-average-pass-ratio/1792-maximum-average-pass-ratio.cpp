class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        int n = classes.size();
        for(int i=0;i<n;i++){
            pq.push(make_pair((double)(classes[i][0]+1)/(double)(classes[i][1]+1) - 
            (double)(classes[i][0])/(double)(classes[i][1]),make_pair(classes[i][0],classes[i][1])));
        }
        while(extraStudents--){
            auto it = pq.top();
            it.second.first = it.second.first + 1;
            it.second.second = it.second.second + 1;
            it.first = (double)(it.second.first+1)/(double)(it.second.second+1)-
            (double)(it.second.first)/(double)(it.second.second);
            pq.pop();
            pq.push(it);
        }
        double avga = 0;
        while(!pq.empty()){
            auto it = pq.top();
            avga += (double)(it.second.first)/(double)(it.second.second);
            pq.pop();
        }
        return (double)avga/(double)(n);
    }
};