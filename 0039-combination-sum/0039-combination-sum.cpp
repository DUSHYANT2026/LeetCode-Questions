class Solution {
private:
    void recurcheck(int indx,int target,vector<int> &nums,vector<int> &ds, 
    vector<vector<int>> &ans){
        if(indx == nums.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[indx] <= target){
        ds.push_back(nums[indx]);
        recurcheck(indx,target-nums[indx],nums,ds,ans);
        ds.pop_back();
        }
        recurcheck(indx+1,target,nums,ds,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        recurcheck(0,target,nums,ds,ans);
        return ans;
    }
};