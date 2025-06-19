class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> pre(n,0), sur(n,0);
        pre[0] = nums[0]; sur[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            pre[i] = max(pre[i-1],nums[i]);
        }
        for(int i=n-2; i>=0; i--){
            sur[i] = min(sur[i+1],nums[i]);
        }
        for(int i=1; i<n-1; i++){
            if(pre[i-1] < nums[i] && nums[i] < sur[i+1]) ans += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) ans  += 1;
        }
        return ans;
    }
};