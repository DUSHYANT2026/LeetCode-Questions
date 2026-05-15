class Solution {
public:
    int findMin(vector<int>& nums) {
      //   int n=nums.size();
      //   int small=INT_MAX;
      //   for(int i=0;i<n;i++){
      //   small=min(small,nums[i]);
      //   }
      // return small;
      sort(nums.begin(),nums.end());
      return nums[0];
    }
};