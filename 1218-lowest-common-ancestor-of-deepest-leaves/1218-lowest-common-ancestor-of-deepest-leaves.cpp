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
    int checkheight(TreeNode* root){
        if(root == NULL) return 0;
        return max(checkheight(root->left) , checkheight(root->right)) + 1;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return root;
        int left = checkheight(root->left);
        int right = checkheight(root->right);

        if(left == right) return root;
        else if(left > right){
            return lcaDeepestLeaves(root->left);
        }
        else{
            return lcaDeepestLeaves(root->right);
        }
    }
};