class Solution {
private:
    void dpcheck(vector<vector<int>> &ans, vector<int> &temp,vector<int> &nums,
    int index){
        int n = nums.size();
    if(index == n){
        ans.push_back(temp);
        return;
    }
    if(index < n){
        temp.push_back(nums[index]);
        dpcheck(ans,temp,nums,index+1);
        temp.pop_back();
        dpcheck(ans,temp,nums,index+1);
    }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dpcheck(ans,temp,nums,0);
        return ans;
    }
};