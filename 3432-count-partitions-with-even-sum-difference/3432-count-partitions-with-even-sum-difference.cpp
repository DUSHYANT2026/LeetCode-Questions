class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0; int sum = 0; int sume = 0;
        for(auto it : nums) sum +=it;
        for(int i=0; i<nums.size()-1; i++){
            sume += nums[i];
            sum -= nums[i];
            if((abs(sume - sum))%2 == 0) ans++;
        }
        return ans;
    }
};