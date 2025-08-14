class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> s = {"999","888","777","666","555","444","333","222","111","000"};

        for(int i=0; i<s.size(); i++){
            string temp = s[i];
            if(num.contains(temp)){
                return temp;
            }
        }
        return "";
    }
};