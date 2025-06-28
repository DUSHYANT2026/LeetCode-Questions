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
public:
    void dfscheck(TreeNode* root, int sum , int target, int &count){
        if(root == NULL) return;
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == target) count = 1;
        }
        dfscheck(root->left,sum,target,count);
        dfscheck(root->right,sum,target,count);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int count = 0;
        dfscheck(root,0,targetSum,count);
        return count == 1;
    }
};