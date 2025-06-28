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
    void dfscheck(TreeNode* root, string sum , int &ans){
        if(root == NULL) return;
        sum += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            ans += stoi(sum);
        }
        dfscheck(root->left,sum,ans);
        dfscheck(root->right,sum,ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfscheck(root,"",ans);
        return ans;
    }
};