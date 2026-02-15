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
    void dfscheck(TreeNode * root, unordered_map<int,int> &mapp){
        if(root == NULL) return;
        
        mapp[root->val]++;
        dfscheck(root->left, mapp);
        dfscheck(root->right, mapp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mapp;
        dfscheck(root, mapp);

        int maxi = INT_MIN;
        for(auto it : mapp){
            maxi = max(maxi, it.second);
        }
        vector<int> ans;
        for(auto it : mapp){
            if(it.second == maxi) ans.push_back(it.first);
        }
        return ans;
    }
};