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
    int minimumOperations(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            vector<int> nums,ans;
            for(int i = 0; i < level; i++){
                TreeNode* temp = q.front();
                nums.push_back(temp->val);
                ans.push_back(temp->val);
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            sort(nums.begin(),nums.end());
            for(int i=0;i<ans.size();i++){
                if(nums[i]!=ans[i]){
                    swap(ans[i],ans[find(ans.begin(),ans.end(),nums[i])-ans.begin()]);
                    count++;
                }
            }
        }
        return count;
    }
};

