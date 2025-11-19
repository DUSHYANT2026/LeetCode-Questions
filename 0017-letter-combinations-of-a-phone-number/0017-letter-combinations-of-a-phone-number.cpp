class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char, string> mapp;
        mapp['2'] = "abc";
        mapp['3'] = "def";
        mapp['4'] = "ghi";
        mapp['5'] = "jkl";
        mapp['6'] = "mno";
        mapp['7'] = "pqrs";
        mapp['8'] = "tuv";
        mapp['9'] = "wxyz";

        if(digits.size() == 1){
            string temp = mapp[digits[0]];
            for(int i=0; i<temp.size(); i++){
                ans.push_back(string(1, temp[i]));
            }
        }
        else if(digits.size() == 2){
            string temp1 = mapp[digits[0]];
            string temp2 = mapp[digits[1]];
            for(int i=0; i<temp1.size(); i++){
                for(int j=0; j<temp2.size(); j++){
                    string x = "";
                    x += temp1[i];
                    x += temp2[j];
                    ans.push_back(x);
                }
            }
        }
        else if(digits.size() == 3){
            string temp1 = mapp[digits[0]];
            string temp2 = mapp[digits[1]];
            string temp3 = mapp[digits[2]];

            for(int i=0; i<temp1.size(); i++){
                for(int j=0; j <temp2.size(); j++){
                    for(int k=0; k <temp3.size(); k++){
                        string x = "";
                        x += temp1[i];
                        x += temp2[j];
                        x += temp3[k];
                        ans.push_back(x);
                    }
                }
            }
        }
        else if(digits.size() == 4){
            string temp1 = mapp[digits[0]];
            string temp2 = mapp[digits[1]];
            string temp3 = mapp[digits[2]];
            string temp4 = mapp[digits[3]];
            for(int i=0; i<temp1.size(); i++){
                for(int j=0; j <temp2.size(); j++){
                    for(int k=0; k <temp3.size(); k++){
                        for(int l=0; l<temp4.size(); l++){
                            string x = "";
                            x += temp1[i];
                            x += temp2[j];
                            x += temp3[k];
                            x += temp4[l];
                            ans.push_back(x);
                        }
                    }
                }
            }
        }
        return ans;
    }
};