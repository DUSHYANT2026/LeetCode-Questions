class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = to_string(stoll(num1) * stoll(num2));
        return ans;
    }
};