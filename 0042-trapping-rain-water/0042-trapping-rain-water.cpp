class Solution {
public:
    int trap(vector<int>& nums) {
        int ans = 0;  int s = 0; int e = nums.size()-1; int smax = 0; int emax = 0;

        while(s < e){
            smax = max(nums[s],smax);
            emax = max(nums[e],emax);
            if(smax <= emax){
                ans +=  smax - nums[s];
                s++;
            }else{
                ans += emax - nums[e];
                e--;
            }
        }
        return ans;
    }
};