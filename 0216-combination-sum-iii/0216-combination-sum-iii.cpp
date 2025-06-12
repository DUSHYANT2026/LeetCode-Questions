class Solution {
private:
    void recurcheck(int indx,int n,int k,vector<int> &nums,vector<int> &ds, 
    vector<vector<int>> &ans){
        if(indx > 9 || n < 0 || k == 0){
            if(n == 0 && k == 0 ){
                ans.push_back(ds);
            }
            return ;
        }
            ds.push_back(nums[indx]);
            recurcheck(indx+1,n-nums[indx],k-1,nums,ds,ans);
            ds.pop_back();
            recurcheck(indx + 1, n, k, nums, ds, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> ds;
        recurcheck(0,n,k,nums,ds,ans);
        return ans;
    }
};