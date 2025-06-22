class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            // string temp = s.substr(i,i+k);
            temp += s[i];
            if (temp.size() == k) {
                ans.push_back(temp);
                temp.clear();
            }
        }
        if (temp.size() != 0) {
            int count = 0;
            count = k - temp.size();
            while (count--) {
                temp += fill;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};