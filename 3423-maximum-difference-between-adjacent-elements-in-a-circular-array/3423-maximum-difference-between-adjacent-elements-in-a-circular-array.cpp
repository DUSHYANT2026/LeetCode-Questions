class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = INT_MIN;
        ans = max(ans,abs(nums[nums.size()-1]-nums[0]));
        for(int i=1; i<nums.size(); i++){
            ans = max(ans,abs(nums[i-1] - nums[i]));
        }
        return ans;
    }
};