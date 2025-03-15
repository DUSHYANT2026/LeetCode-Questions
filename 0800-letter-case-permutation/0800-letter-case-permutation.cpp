class Solution {
private:
    void dpcheck(vector<string> &ans,int n,string s,string temp,int index){
        if(n == temp.size()){
            ans.push_back(temp);
            return;
        }
        if(isdigit(s[index])){
            temp += s[index];
            dpcheck(ans,n,s,temp,index+1);
        }
        else{
            string small = temp;
            small += tolower(s[index]);
            dpcheck(ans,n,s,small,index+1);
            temp += toupper(s[index]);
            dpcheck(ans,n,s,temp,index+1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();
        string temp = "";
        dpcheck(ans,n,s,temp,0);
        return ans;
    }
};