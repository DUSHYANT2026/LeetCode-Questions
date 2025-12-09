class Solution {
public:
    bool hasMatch(string s, string p) {
        int check = 0;
        for(int i=0; i<p.size(); i++){
            if(p[i] == '*') check = i;
        }
        string first = p.substr(0,check);
        string second = p.substr(check+1);

       int x = s.find(first); int y = s.rfind(second);
        
        return x != -1 && y != -1 && x + first.size() <= y;
    }
};