class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        unordered_map<int,int> mapp;

        int ans = 0;
        int j = 0;
        for(int i=0; i<nums.size(); i++){
            mapp[nums[i]]++;
            if(mapp[0] > k){
                while(mapp[0] > k){
                    mapp[nums[j]]--;
                    if(mapp[nums[j]] == 0) mapp.erase(nums[j]); 
                    j++;
                }
            }
            ans = max(ans, i - j+1);
        }
        return ans;
    }
};