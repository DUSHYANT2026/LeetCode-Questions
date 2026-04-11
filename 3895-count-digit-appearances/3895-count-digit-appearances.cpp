class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        vector<int> ans(10,0);
        for(auto it : nums){
            while(it != 0){
                ans[it%10]++;
                it /= 10;
            }
        }
        return ans[digit];
    }
};