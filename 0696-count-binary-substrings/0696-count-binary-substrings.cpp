// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         int ans = 0;
//         int n = s.size();

//         for (int i = 0; i < n; i++) {
//             int count1 = 1;
//             int count2 = 0; 
//             int j = i;
//             while (j + 1 < n && s[j] == s[j + 1]) {
//                 count1++;
//                 j++;
//             }
//             j++; 
//             if (j < n) {
//                 count2 = 1;
//                 while (j + 1 < n && s[j] == s[j + 1] && count2 < count1) {
//                     count2++;
//                     j++;
//                 }
//             }
//             if (count1 == count2) {
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1;
        int index = 0;
        vector<int> ans(s.size());
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                ans[index++] = count;
                count = 1;
            }
        }
        ans[index++] = count;

        int sum = 0;
        for (int i = 0; i < index - 1; i++) {
            sum += min(ans[i], ans[i + 1]);
        }
        return sum;
    }
};