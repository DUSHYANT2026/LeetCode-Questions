// class Solution {
// private:
//     void recurcheck(int indx,int target,vector<int> &nums,vector<int> &ds,
//     vector<vector<int>> &ans){
//             if(target == 0){
//                 ans.push_back(ds);
//                 return ;
//             }
//         for(int i=indx;i<nums.size();i++){
//             if(i > indx && nums[i] == nums[i-1]) continue;
//             if(nums[i] <= target){
//               ds.push_back(nums[i]);
//               recurcheck(i+1,target-nums[i],nums,ds,ans);
//               ds.pop_back();
//             }
//         }
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
//         vector<int> ds;
//         recurcheck(0,target,nums,ds,ans);
//         return ans;
//     }
// };


// class Solution {
// private:
//     void dpcheck(int index,int n,int target,vector<int> &nums,vector<int> &temp,
//     set<vector<int>> &allset){            // this code is correct but give time limit error because it check all the subset one by one
//         if(index == n){
//             int sum = 0;
//             for(auto it : temp) sum += it;
//             if(sum == target){
//                 allset.insert(temp);
//             }
//         }
//         if(index < n){
//             dpcheck(index+1,n,target,nums,temp,allset);
//             temp.push_back(nums[index]);
//             dpcheck(index+1,n,target,nums,temp,allset);
//             temp.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
//         vector<int> temp;
//         set<vector<int>> allset;
//         int n = nums.size();
//         dpcheck(0,n,target,nums,temp,allset);

//         for(auto it : allset) ans.push_back(it);

//         return ans;
//     }
// };



class Solution {
private:
    void dpcheck(int index, int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) break;

            temp.push_back(nums[i]);
            dpcheck(i + 1, target - nums[i], nums, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dpcheck(0, target, nums, temp, ans);
        return ans;
    }
};
