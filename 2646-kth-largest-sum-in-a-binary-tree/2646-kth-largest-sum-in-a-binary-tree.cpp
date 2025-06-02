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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        queue<TreeNode*> q;
        q.push(root);

        vector<long long> nums;

        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for(int i=0; i<size; i++){
                auto it = q.front(); q.pop();
                sum += it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            nums.push_back(sum);
        }
        sort(nums.rbegin(),nums.rend());
        return (k > nums.size()) ? -1 : nums[k-1];
    }
};