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
// class Solution {
// public:
//     int subtreesum(TreeNode * root, vector<int>& dp){
//         if(root == NULL) return 0;
//         if(dp[root] != NULL) return dp[root];
//         int left = subtreesum(root->left);
//         int right  = subtreesum(root->right);
//         int sum = root->val + left + right;
//         return dp[root] = sum;
//     }
//     void dfscheck(TreeNode * root, vector<int> &nums){
//         if(root == NULL) return;
//         dfscheck(root->left, nums);
//         nums.push_back(root->val);
//         dfscheck(root->right, nums); 
//     }
//     bool checkbst(TreeNode* root){
//         vector<int> nums;
//         dfscheck(root, nums);
        
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i-1] >= nums[i]) return false;
//         }
//         return true;
//     }
//     int maxSumBST(TreeNode* root) {
//         if(root == NULL) return 0;
//         int ans = 0;

//         vector<int> dp
//         if(checkbst(root)){
//             ans = max(ans, subtreesum(root));
//         }
//         ans = max(ans, maxSumBST(root->left));
//         ans = max(ans, maxSumBST(root->right));

//         return ans;
//     }
// };


class Solution {
public:
    unordered_map<TreeNode*, int> memoSum;
    unordered_map<TreeNode*, bool> memoBST;
    unordered_map<TreeNode*, int> memoMin, memoMax;

    int subtreesum(TreeNode * root){
        if(root == NULL) return 0;
        if(memoSum.count(root)) return memoSum[root];
        
        int left = subtreesum(root->left);
        int right  = subtreesum(root->right);
        int sum = root->val + left + right;
        
        return memoSum[root] = sum;
    }

    void updateRange(TreeNode* root) {
        if (!root || memoMin.count(root)) return;
        updateRange(root->left);
        updateRange(root->right);
        
        int mn = root->val, mx = root->val;
        if (root->left) {
            mn = min(mn, memoMin[root->left]);
            mx = max(mx, memoMax[root->left]);
        }
        if (root->right) {
            mn = min(mn, memoMin[root->right]);
            mx = max(mx, memoMax[root->right]);
        }
        memoMin[root] = mn;
        memoMax[root] = mx;
    }

    bool checkbst(TreeNode* root){
        if(root == NULL) return true;
        if(memoBST.count(root)) return memoBST[root];

        updateRange(root);

        bool leftIsBST = checkbst(root->left);
        bool rightIsBST = checkbst(root->right);
        
        bool leftOk = !root->left || root->val > memoMax[root->left];
        bool rightOk = !root->right || root->val < memoMin[root->right];

        return memoBST[root] = (leftIsBST && rightIsBST && leftOk && rightOk);
    }

    int maxSumBST(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;

        if(checkbst(root)){
            ans = max(ans, subtreesum(root));
        }
        
        ans = max(ans, max(maxSumBST(root->left), maxSumBST(root->right)));

        return ans;
    }
};