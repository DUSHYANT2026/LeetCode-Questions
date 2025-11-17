class Solution {
public:
    string check(string s){
        string ans = "";

        for(int i=0; i<s.size()-1; i++){
            int x = s[i] - '0';
            int y = s[i+1] - '0';
            cout<<x<<" "<<y<<endl;
            ans += (x+y)%10 + '0';
        }
        return ans;
    }
    bool hasSameDigits(string s) {
        while(s.size() != 2){
            string temp = check(s);
            s = temp;
        }
        int ans = stoi(s);
        return (ans%11 == 0) ? true : false;
    }
};