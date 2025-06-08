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
        vector<string> ans;
        // for(int i=1; i<=9 && i<=n; i++){
        //     dfscheck(i,n,ans);
        // }

        for(int i=1; i<=n; i++){
            ans.push_back(to_string(i));
        }
        sort(ans.begin(),ans.end());
        vector<int> nums;
        for(auto it : ans) nums.push_back(stoi(it));
        return nums;
    }
};