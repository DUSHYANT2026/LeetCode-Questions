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
//     void countnode(TreeNode* root, int &count){
//         if(root == NULL) return;
//         count++;
//         countnode(root->left, count);
//         countnode(root->right, count);
//     }
//     int height(TreeNode* root, int node){
//         if(root == NULL || root->val == node) return 0;
//         int left = 0; int right = 0;
        
//         left = height(root->left, node);
//         right = height(root->right, node);

//         return max(left, right) + 1;
//     }
//     vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
//         int n = 0;
//         countnode(root, n);
//         vector<int> ans(n+1 , 0);
//         for(int i=1; i<=n; i++){
//            ans[i] = (height(root, i));
//         }
//         vector<int> nums;
//         for(auto it : queries){
//             nums.push_back(ans[it] - 1);
//         }
//         return nums;
//     }
// };


class Solution {
public:
    unordered_map<int,int> depth;
    unordered_map<int,int> height;
    unordered_map<int, vector<int>> levelHeights;

    int dfs(TreeNode* root, int d) {
        if(!root) return -1;

        depth[root->val] = d;

        int left = dfs(root->left, d+1);
        int right = dfs(root->right, d+1);

        int h = max(left, right) + 1;
        height[root->val] = h;

        levelHeights[d].push_back(h);

        return h;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);

        unordered_map<int, pair<int,int>> bestTwo;

        for(auto &it : levelHeights) {
            int level = it.first;
            int max1 = -1, max2 = -1;

            for(int h : it.second) {
                if(h > max1) {
                    max2 = max1;
                    max1 = h;
                } else if(h > max2) {
                    max2 = h;
                }
            }

            bestTwo[level] = {max1, max2};
        }

        vector<int> ans;

        for(int q : queries) {
            int d = depth[q];
            int h = height[q];

            int max1 = bestTwo[d].first;
            int max2 = bestTwo[d].second;

            if(h == max1)
                ans.push_back(d + max2);
            else
                ans.push_back(d + max1);
        }

        return ans;
    }
};

