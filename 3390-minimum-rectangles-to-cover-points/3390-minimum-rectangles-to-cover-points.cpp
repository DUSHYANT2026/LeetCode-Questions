class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& nums, int w) {
        int ans = 1; sort(nums.begin(),nums.end()); int update = nums[0][0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i][0] - update > w ){ ans++; update = nums[i][0];}
        }
        return ans;
    }
};