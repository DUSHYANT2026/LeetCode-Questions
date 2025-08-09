class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};