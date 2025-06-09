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
    void dfscheck(TreeNode* root, int val , vector<int> &nums){
        if(root == NULL) return;
        dfscheck(root->left,val,nums);
        if(root->val != val) nums.push_back(root->val);
        dfscheck(root->right,val,nums);
    }
    TreeNode* dfstree(int s, int e, vector<int> &nums){
        if(s > e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfstree(s,mid-1,nums);
        root->right = dfstree(mid+1,e,nums);
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> nums;
        dfscheck(root,key,nums);
        return dfstree(0,nums.size()-1,nums);
    }
};