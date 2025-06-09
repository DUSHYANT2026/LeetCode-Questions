class Solution {
private:
    void dpcheck(int index1, int index2, int n,vector<string> &ans, string temp){
        if((index1 + index2 )== 2*n){
            ans.push_back(temp);
            return;
        }
        if(index1 < n){
            temp.push_back('(');
            dpcheck(index1+1,index2,n,ans,temp);
            temp.pop_back();
        }
        if(index2 < index1){
            temp.push_back(')');
            dpcheck(index1,index2+1,n,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dpcheck(0,0,n,ans,"");
        return ans;
    }
};