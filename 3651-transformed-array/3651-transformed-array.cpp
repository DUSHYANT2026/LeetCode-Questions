class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                ans[i] = nums[i];
            }
            else{
                int index;

                if(nums[i] > 0) index = (i + nums[i])%n; 
                else {
                    index = ((i + nums[i]) %n + n)%n;
                }
                ans[i] = nums[index];
            }
        }
        return ans;
    }
};