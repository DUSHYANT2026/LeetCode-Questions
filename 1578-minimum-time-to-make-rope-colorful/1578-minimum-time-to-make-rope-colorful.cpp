class Solution {
public:
    int minCost(string nums, vector<int>& time) {
        
        int ans = 0;
        int index = INT_MAX; int newindex = INT_MIN;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]){
                ans += min(time[i-1],time[i]);
                time[i] = max(time[i-1],time[i]);
            }
        }
        return ans;
    }
};
