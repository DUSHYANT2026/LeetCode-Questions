class Solution {
private:
    void dfscheck(int temp, int n, vector<int> &ans){
        if(temp > n) return;
        ans.push_back(temp);
        for(int i=0; i<=9 && i<=n; i++){
            dfscheck(temp*10+i,n,ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=9 && i<=n; i++){
            dfscheck(i,n,ans);
        }
        return ans;
    }
};