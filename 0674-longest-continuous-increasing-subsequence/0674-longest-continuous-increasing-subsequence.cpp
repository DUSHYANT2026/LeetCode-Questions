class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int temp = nums[0];
        int count = 1;  int ans = 0;
        for(int i=1; i<nums.size(); i++){
            if(temp < nums[i]){
                count++;
            }
            else{
                ans = max(ans,count);
                count = 1;
            }
            ans = max(ans,count);
            temp = nums[i];
        }
        return ans;
    }
};