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
    TreeNode* dfscheck(int left,int right,vector<int> &nums){
        if(left>right) return nullptr;
        int maxindex=left;
        for(int i=left+1;i<=right;i++){
            if(nums[i]>nums[maxindex])
            maxindex=i;
        }
        TreeNode* root=new TreeNode(nums[maxindex]);
        root->left=dfscheck(left,maxindex-1,nums);
        root->right=dfscheck(maxindex+1,right,nums);
        return root;
    }
    void inorder(TreeNode* root, vector<int> &nums){
        if(root == NULL) return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> nums;
        inorder(root,nums);
        nums.push_back(val);
        
        return dfscheck(0,nums.size()-1,nums);
    }
};