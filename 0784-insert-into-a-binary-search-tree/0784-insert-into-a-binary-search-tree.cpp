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
    TreeNode* dfschecktree(int s, int e, vector<int> &nums){
        if(s > e) return NULL;
        int mid = (e+s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfschecktree(s,mid-1,nums);
        root->right = dfschecktree(mid+1,e,nums);
        return root; 
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int> nums;
        dfscheck(root,nums);
        nums.push_back(val);
        sort(nums.begin(),nums.end());
        return dfschecktree(0,nums.size()-1,nums);
    }
};