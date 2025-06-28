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
    void dfscheck(TreeNode* root, vector<int> temp , int target, vector<vector<int>> &ans){
        if(root == NULL) return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            int sum = 0;
            for(auto it : temp) sum += it;
            if(sum == target) ans.push_back(temp);
        }
        dfscheck(root->left,temp,target,ans);
        dfscheck(root->right,temp,target,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfscheck(root,temp,targetSum,ans);
        return ans;
    }
};