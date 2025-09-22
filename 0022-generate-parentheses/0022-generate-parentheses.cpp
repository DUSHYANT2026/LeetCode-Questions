// class Solution {
// private:
//     void dpcheck(int index1, int index2, int n,vector<string> &ans, string temp){
//         if((index1 + index2 )== 2*n){
//             ans.push_back(temp);
//             return;
//         }
//         if(index1 < n){
//             temp.push_back('(');
//             dpcheck(index1+1,index2,n,ans,temp);
//             temp.pop_back();
//         }
//         if(index2 < index1){
//             temp.push_back(')');
//             dpcheck(index1,index2+1,n,ans,temp);
//             temp.pop_back();
//         }
//     }
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         dpcheck(0,0,n,ans,"");
//         return ans;
//     }
// };


class Solution {
public:
    bool checkvalid(string s){
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push('(');
            }else{
                if(st.empty()) return false;
                if(st.top() == '(') st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string s = "";
        for(int i=0; i<n; i++) s += '(';
        for(int i=0; i<n; i++) s += ')';

        do{
            if(checkvalid(s)) ans.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        return ans;
    }
};