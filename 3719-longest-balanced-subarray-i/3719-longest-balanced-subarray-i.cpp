class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size()-1; i++){
            set<int> counte,counto;
            for(int j=i; j<nums.size(); j++){
                if(nums[j]%2 == 0) counte.insert(nums[j]);
                else counto.insert(nums[j]);
                if(counte.size() == counto.size()) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};