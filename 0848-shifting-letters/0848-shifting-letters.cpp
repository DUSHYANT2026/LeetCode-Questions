class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum = 0;
        for(auto it : shifts) sum += it;
        string ans = "";
        int x = 0;
        for(int i=0; i<s.size(); i++){
            int temp = (sum - x)%26;
            auto it = s[i];
            it = 'a' + (it - 'a' + temp)%26;
            ans += it;
            x += shifts[i];
        }
        return ans;
    }
};