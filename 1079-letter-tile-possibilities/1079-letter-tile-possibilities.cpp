class Solution {
private:
 void backtrackcheck(vector<int>& nums, int& ans){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0){
                ans++;
                nums[i]--;
                backtrackcheck(nums, ans);
                nums[i]++;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<int,int> mapp;
        for(auto it : tiles){
            mapp[it]++;
        }
        vector<int> nums;
        int ans = 0;
        for(auto it : mapp){
            nums.emplace_back(it.second);
        }
        backtrackcheck(nums,ans);
        return ans;
    }
};