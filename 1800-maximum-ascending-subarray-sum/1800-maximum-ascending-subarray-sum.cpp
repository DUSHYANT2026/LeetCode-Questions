class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int sum = nums[0];

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                sum += nums[i+1];
            }else{
                ans = max(ans,sum);
                sum = nums[i+1];
            }
        }
        return max(ans,sum);
    }
};