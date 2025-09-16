class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,-1), sur(n,-1);
        pre[0] = nums[0]; sur[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            pre[i] = max(pre[i-1],nums[i]);
        }
        for(int i=n-2; i>=0; i--){
            sur[i] = min(sur[i+1],nums[i]);
        }
        for(int i=1; i<n; i++){
            if(pre[i-1] <= sur[i]) return i;
        }
        return -1;
    }
};