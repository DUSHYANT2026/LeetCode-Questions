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
    void dfscheck(TreeNode* root, int &nums){
        if(root == NULL) return;
        dfscheck(root->left,nums);
        nums += (root->val);
        dfscheck(root->right,nums);
    }
    int dfscheck2(TreeNode* root, int &ans, int &totalsum){
        int sum = 0;
        if(root == NULL) return sum; 
        sum = root->val +  dfscheck2(root->left,ans, totalsum) +  dfscheck2(root->right,ans, totalsum);
        ans = max(ans, (totalsum-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;
        int totalsum = 0;
        dfscheck(root,totalsum);

        int ans = 0;
        dfscheck2(root, ans, totalsum);
        return ans;
    }
};