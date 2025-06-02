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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0; int maxsum = INT_MIN;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto size = q.size();
            int sum = 0;
            for(int i=0; i<size; i++){
                auto it = q.front(); q.pop();
                sum += it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(sum > maxsum){
                ans = level;
                maxsum = sum;
            }
            level++;
        }
        return ans;
    }
};