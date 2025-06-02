/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<Node*> q; 
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                auto it = q.top(); q.pop();
                temp.push_back(it->val);
                for(auto i : it->children){
                    q.push(i);
                }
            }
            for(auto it : temp) ans.push_back(it);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};