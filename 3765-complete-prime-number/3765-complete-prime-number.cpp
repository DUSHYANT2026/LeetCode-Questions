class Solution {
public:
    bool checkprime(int n){
        if(n <= 1) return true;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    bool completePrime(int n) {
        if(n == 1 || n == 2 || n == 3 || n == 5 || n == 7) return true;

        string s = to_string(n);

        string temp = ""; string temp2 = "";
        for(int i=0; i<s.size(); i++){
            temp += s[i];
            temp2 = s[s.size()-1-i] + temp2;
            if(checkprime(stoi(temp)) == false) return false;
            if(checkprime(stoi(temp2)) == false) return false;
        }
        return true;
    }
};