class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                cout<<i<<endl;
                ans = min(ans, abs(i-start));
            }
            // if(nums[nums.size()-1-i] == target) ans = min(ans, abs( nums.size()-1-i - start));
        }
        return ans;
    }
};