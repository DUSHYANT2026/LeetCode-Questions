class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long> presum(nums.size(),0); 
        vector<int> surmin(nums.size(),INT_MAX);
        presum[0] = (long long)nums[0];

        for(int i=1; i<nums.size(); i++){
            presum[i] += (long long)nums[i] + presum[i-1];
        }

        surmin[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2; i >= 0; i--){
            surmin[i] = min(surmin[i+1],nums[i]); 
        }

        long long ans  = -1e10;
        for(int i=0; i<nums.size()-1; i++){
            long long temp = presum[i] - surmin[i+1];
            cout<<temp<<" ";
            if(ans < temp){
                ans = temp;
            }
        }
        return ans;
    }
};