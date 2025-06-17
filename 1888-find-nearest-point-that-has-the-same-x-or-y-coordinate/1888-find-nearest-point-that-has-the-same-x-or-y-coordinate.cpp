class Solution {
public:
    bool check(int x, int y, int nx, int ny){
        return (x == nx) || (y == ny);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<int,int>> nums;
        for(int i=0; i<points.size(); i++){
            int nx = points[i][0]; int ny = points[i][1]; 
            if(check(x,y,nx,ny)) {
                int temp = abs(x-points[i][0]) + abs(y-points[i][1]);
                nums.push_back({temp,i});
            }
        }
        sort(nums.begin(),nums.end());
        return nums.size() == 0 ? -1 : nums[0].second;
    }
};