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
    int dfscheck(TreeNode* root){
        if(root == NULL) return 0;
        int left = dfscheck(root->left);
        int right = dfscheck(root->right);
        return max(left,right) + 1;
    }
     
    void newdfscheck(int height, TreeNode* root, vector<vector<string>> &ans, int row, int col){
        if(root == NULL) return;
         
        ans[row][col] = to_string(root->val);
         
        newdfscheck(height, root->left, ans, row+1, col-pow(2,height-row-2));
        newdfscheck(height, root->right, ans, row+1, col+pow(2,height-row-2)); 
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = 0;
        height = dfscheck(root);
          
        vector<vector<string>> ans(height, vector<string>(pow(2,height)-1, ""));
        newdfscheck(height, root, ans, 0, ((pow(2,height)-1)-1)/2);
        return ans;
    }
};