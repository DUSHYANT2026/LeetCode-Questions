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
    int dfscheck(TreeNode* root){
        if (root == NULL) return 0;
        int left = dfscheck(root->left);
        int right = dfscheck(root->right);
        if (left == 0 || right == 0) {
            return max(left, right) + 1;
        }
        return min(left, right) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        return dfscheck(root);
    }
};