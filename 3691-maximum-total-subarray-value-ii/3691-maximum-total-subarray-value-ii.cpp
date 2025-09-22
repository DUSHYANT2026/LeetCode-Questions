class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int ans = 0; int maxi = 0; int mini = 1e9;
        for(int i=0; i<nums.size(); i++){
            maxi = max(nums[i],maxi);
            mini = min(nums[i],mini);
        }
        return (long long)k*(maxi-mini);
    }
};