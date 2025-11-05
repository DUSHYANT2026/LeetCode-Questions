class Solution {
public:
    int maxArea(vector<int>& nums) {
        int ans = INT_MIN;
        int i = 0; int j = nums.size()-1;

        while(i < j){
            if(nums[i] < nums[j]){
                ans = max(ans, nums[i] * abs(i-j));
                i++;
            }
            else {
                ans = max(ans, nums[j] * abs(i-j));
                j--;
            }
        }
        return ans;
    }
};