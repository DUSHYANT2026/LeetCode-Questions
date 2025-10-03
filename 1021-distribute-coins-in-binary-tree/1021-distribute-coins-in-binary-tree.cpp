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
    int dfscheck(TreeNode* root,int &ans){
      if(root == NULL) return 0;
      int left = dfscheck(root->left,ans);
      int right =  dfscheck(root->right,ans);
      ans+=abs(left);
      ans+=abs(right);
      return left+right+root->val-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        if(root == NULL) return 0;
        int ans=0;
        dfscheck(root, ans);
        return ans;
    }
};