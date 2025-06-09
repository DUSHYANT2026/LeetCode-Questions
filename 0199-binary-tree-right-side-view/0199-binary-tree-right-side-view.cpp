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
    void dfscheck(TreeNode* root, vector<int> &nums, int level){
        if(root == NULL) return;
        if(nums.size() == level) nums.push_back(root->val);
        dfscheck(root->right,nums,level+1);
        dfscheck(root->left,nums,level+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nums;
        dfscheck(root,nums,0);
        return nums;
    }
};