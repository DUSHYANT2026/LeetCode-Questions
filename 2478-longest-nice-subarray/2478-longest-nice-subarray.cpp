class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int count = 0; int start = 0, ans = 0;
        for(int i = 0; i <nums.size(); i++) {
            while((count & nums[i]) != 0) {
                count ^= nums[start];  
                start++;
            }
            count |= nums[i]; 
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};