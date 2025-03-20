class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = INT_MIN;
        int ans2 = INT_MAX;
        int sum1 = 0; int sum2 = 0l;
        for(int i=0; i<nums.size(); i++){
            sum1 += nums[i];
            ans1 = max(ans1,sum1); 
            if(sum1 < 0) sum1 = 0;
        }
        for(int i=0; i<nums.size(); i++){
            sum2 += nums[i];
            ans2 = min(ans2,sum2);
            if(sum2 > 0) sum2 = 0;
        }
        return max(ans1,abs(ans2));
    }
};