class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int ans = 0;
        unordered_map<char,int> mapp;
        int x = -1;
        for(int i=0; i<nums.size(); i++){
            if(mapp.count(nums[i]) > 0){
                x = max(mapp[nums[i]],x);
            }
            ans = max(ans,i-x);
            mapp[nums[i]] = i;
        }
        return ans;
    }
};