class Solution {
private:
    void dfscheck(int index, int n, vector<int> &temp, vector<int> &nums, vector<vector<int>> & ans){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<n; i++){
            temp.push_back(nums[i]);
            swap(nums[index],nums[i]);
            dfscheck(index+1,n,temp,nums,ans);
            swap(nums[index],nums[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfscheck(0,nums.size(),temp,nums,ans);
        return ans;
    }
};