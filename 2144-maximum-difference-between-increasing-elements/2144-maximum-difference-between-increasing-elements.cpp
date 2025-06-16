class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int small = INT_MAX; int large = 0; int ans = 0;

        for(int i=0; i<nums.size()-1;  i++){
            for(int j=i+1; j<nums.size(); j++){
                if(i < j)
                ans = max(ans , (nums[j] - nums[i]));
            }
        }
        return ans == 0 ? -1 : ans;
    }
};