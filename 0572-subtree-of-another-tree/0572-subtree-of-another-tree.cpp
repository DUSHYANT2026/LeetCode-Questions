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
// class Solution {
// public:
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(root == NULL && subRoot == NULL) return true;
//         if(root == NULL || subRoot == NULL) return false;

//         if(root->val == subRoot->val){
//             return isSubtree(root->left,subRoot->left) && isSubtree(root->right,subRoot->right);
//         }
//         return false;
//     }
// };

class Solution {
private:
    bool dfscheck(TreeNode* x, TreeNode* y){
        if(x == NULL && y == NULL) return true;
        if(x == NULL || y == NULL) return false;
        return (x->val == y->val) && dfscheck(x->left,y->left) && dfscheck(x->right,y->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;

        if (dfscheck(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
