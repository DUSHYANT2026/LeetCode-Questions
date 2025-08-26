class Solution {
public:
    string numtobinary(int n){
        string ans = "";
        while(n != 0){
            ans += to_string(n%2) ;
            n /= 2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        string ans ="";

        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,7));
        int d = stoi(date.substr(8,10));

        return numtobinary(y)+"-"+numtobinary(m)+"-"+numtobinary(d); 
    }
};