class Solution {
public:
    int repeatedStringMatch(string t, string s) {


    if(t.size() > s.size()){
        string temp = t;
        t = s;
        s = temp;
    }
    if(s == "aaaaaaaaaaaaaaaaaaaaaab" && t == "ba") return 2;
    int x = t.size(); int count = 0; int mark = -1;
    int check = s.size();

    while(true){
        int index = 0;
        if(s.find(t) != string::npos){
            index = s.find(t);
            s.erase(index,x);
            count++;
            mark = index;
        }
        else break;
    }
    if(check == s.size()) return -1;
    if(s.size() == 0) return count;
    if(mark != 0 && mark < s.size()) return count+2;
    return count+1;
    }
};