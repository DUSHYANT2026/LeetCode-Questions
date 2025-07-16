class Solution {
public:
    void dpcheck(int index, vector<vector<int>> &ans, vector<int> &nums, vector<int> temp){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        dpcheck(index+1,ans,nums,temp);
        temp.pop_back();
        dpcheck(index+1,ans,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dpcheck(0,ans,nums,temp);
        return ans;
    }
};