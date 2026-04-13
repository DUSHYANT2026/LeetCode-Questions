class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int n = nums.size()-1;
        for(int i=0; i<=nums.size()/2; i++){
            if(nums[i] == target) ans = min(ans, abs(i-start));
            if(nums[n-i] == target) ans = min(ans, abs(abs(n-i) - start));
        }
        return ans;
    }
};