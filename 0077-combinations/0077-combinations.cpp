class Solution {
private:
    void dfscheck(int node,int n, int k, vector<int> &temp,vector<vector<int>>& ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i=node; i<=n; i++){
            temp.push_back(i);
            dfscheck(i+1,n,k,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfscheck(1,n,k,temp,ans);
        return ans;
    }
};