class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(true){
            if(s.size() > k) break;
            string temp;
            for(auto it : s){
                if(it == 'z') temp += 'a';
                else temp += it + 1;
            }
            cout<<temp<<endl;
            s += temp;
        }
        return s[k-1];
    }
};

