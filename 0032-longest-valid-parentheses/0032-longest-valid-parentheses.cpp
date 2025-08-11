// class Solution {
// public:
// bool checkvalid(string s) {
//     stack<char> st;

//     for (char c : s) {
//         if (c == '(') {
//             st.push(c);
//         } else {
//             if (!st.empty() && st.top() == '(') {
//                 st.pop();
//             } else {
//                 return false; 
//             }
//         }
//     }
//     return st.empty(); 
// }
//     int longestValidParentheses(string s) {
//     int n = s.size();
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         string temp = "";
//         for(int j=i; j<n; j++){
//             temp += s[j];
//             int x = temp.size();
//             if(checkvalid(temp)){
//                 ans = max(ans,x);
//             }
//         }
//     }
//     return ans;
//     }
// };



class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        stack<int> st;

        st.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        return maxLength;
    }
};
