class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       int n = nums.size();
       sort(begin(nums),end(nums));
       int s = 0; int e = n-1; int count=0; int mod=1e9+7;
        vector<int> pows(n, 1);
        for(int i=1; i<n ; i++) pows[i] = pows[i-1]*2 % mod;
        while(s <= e){
            if(nums[s]+nums[e] <= target){
               count = (count + pows[e - s]) % mod;
               s++;
            }
            else e--;
        }
       return count;
    }
};