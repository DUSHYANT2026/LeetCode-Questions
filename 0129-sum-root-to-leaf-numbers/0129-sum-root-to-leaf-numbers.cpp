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
    int dfscheck(TreeNode*  root,int& sum,int node){
        if(root == NULL) return 0;
        node = node*10+root->val;
        dfscheck(root->left,sum,node);
        dfscheck(root->right,sum,node);
        if(root->left == NULL && root->right==NULL){
            sum+=node;
        }
        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        return dfscheck(root,sum,0);
    }
};