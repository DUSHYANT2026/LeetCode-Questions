class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int i = nums[0];
        for(auto it : nums){
            if(it - i > k){
                count++;
                i = it;
            }
        }
        return count+1;
    }
};