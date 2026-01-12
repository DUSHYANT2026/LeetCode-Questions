class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        vector<int> pre(n, 0);
        pre[0] = 1;

        set<char> st; string temp = "";
        temp += s[0]; st.insert(s[0]);
        int count = 1;

        for(int i=1; i<n; i++){
            temp += s[i];
            st.insert(s[i]);
            if(st.size() == (temp.size())%3){
                count++;
                pre[i] += count; 
            }
            else pre[i] = pre[i-1];
        }
        return pre[n-1];
    }
};