class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int index = nums[0];
        for(auto it : nums){
            if(it - index > k){ 
                ans++;
                index = it;
            }
        }
        return ans;
    }
};