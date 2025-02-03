class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1; int ans1 = 1; int count = 1; int count1 = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] > nums[i]){
                count++;
                ans = max(ans,count);
                count1 = 1;
            }
            else if(nums[i-1] < nums[i]){
                count1++;
                ans1 = max(ans,count1);
                count = 1; 
            }
            else{
                count1 = 1; count = 1;
            }
        }
        return max(ans,ans1);
    }
};