class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = INT_MIN; int sum = 0;
        int j = 0;
        unordered_map<int,int> mapp;
        for(int i=0; i<nums.size(); i++){
            if(mapp.count(nums[i]) > 0){
                while(j <= mapp[nums[i]]){
                    sum -= nums[j];
                    j++;
                }
            }
            sum += nums[i];
            ans = max(ans,sum);
            mapp[nums[i]] = i;
        }
        return ans;
    }
};