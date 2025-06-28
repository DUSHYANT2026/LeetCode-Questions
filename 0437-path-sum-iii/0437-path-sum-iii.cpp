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
int count=0;
void dfscheck(TreeNode*  &root , long long  targetSum ){
    if(root ==NULL )
    return ;
    if(root->val ==  targetSum ){
        count++;
    }
    dfscheck(root->left,targetSum-root->val);
    dfscheck(root->right,targetSum-root->val);
}
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
        return 0;
        dfscheck(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count; 
    }
};