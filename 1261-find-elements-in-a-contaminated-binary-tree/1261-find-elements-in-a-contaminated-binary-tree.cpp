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
class FindElements {
private:
    unordered_map<int,int> mapp;
private:
void dfscheck(TreeNode* root,int val){
        if(root == NULL) return;
        mapp[val] = val;
        dfscheck(root->left,val*2+1);
        dfscheck(root->right,val*2+2);
    }
    
public:
    FindElements(TreeNode* root) {
        dfscheck(root,0);
    }
    
    bool find(int target) {
        return mapp.count(target)>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */