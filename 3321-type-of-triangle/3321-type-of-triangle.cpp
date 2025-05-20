class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum1 = 0; int sum2 = 0; int sum3 = 0;
        sum1 = nums[0] + nums[1];
        sum2 = nums[1] + nums[2];
        sum3 = nums[0] + nums[2];
        if(sum1 > nums[2] && sum2 > nums[0] && sum3 > nums[1]){
          if(nums[0] == nums[1] &&  nums[1] == nums[2]) return "equilateral";
          if(nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) return "scalene";
          return "isosceles"; 
        }
        return "none";
    }
};