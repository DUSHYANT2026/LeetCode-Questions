/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfscheck(TreeNode* root, vector<int> &nums){
        if(root == NULL) return;
        dfscheck(root->left,nums);
        nums.push_back(root->val);
        dfscheck(root->right,nums);
    }
    int findmin(vector<int> &nums, int target){
        int s = 0; int e = nums.size()-1;
        int ans = -1;
        while(s <= e){
            int mid = (e+s)/2;
            if(nums[mid] == target) return nums[mid];
            else if(nums[mid] < target){
                ans = nums[mid];
                s = mid+1;
            }
            else e = mid -1;
        }
        return ans;
    }
    int findmax(vector<int> &nums, int target){
        int s = 0; int e = nums.size()-1;
        int ans = -1;
        while(s <= e){
            int mid = (s+e)/2;
            if(nums[mid] == target) return nums[mid];
            else if(nums[mid] > target){
                ans = nums[mid];
                e = mid-1;
            } 
            else s = mid+1;
        }
        return ans;
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> nums;
        dfscheck(root,nums);

        for(auto it : queries){
            ans.push_back({findmin(nums,it),findmax(nums,it)});
        }
        return ans;
    }
};