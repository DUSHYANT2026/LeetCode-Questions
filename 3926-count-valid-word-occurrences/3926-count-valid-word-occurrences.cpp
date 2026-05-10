class Solution {
public:
    bool check(char c){
        return c >= 'a' && c <= 'z';
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";

        for(auto it : chunks) s += it;

        vector<string> nums;
        string temp = "";

        for(int i = 0; i < s.size(); i++){
            if(check(s[i])){
                temp += s[i];
            }
            else if(
                s[i] == '-' &&
                i > 0 &&
                i + 1 < s.size() &&
                check(s[i - 1]) &&
                check(s[i + 1])
            ){
                temp += '-';
            }

            else{
                if(!temp.empty()){
                    nums.push_back(temp);
                    temp = "";
                }
            }
        }
        
        if(!temp.empty())
            nums.push_back(temp);

        unordered_map<string, int> mapp;

        for(auto it : nums)
            mapp[it]++;

        vector<int> ans;

        for(auto it : queries){
            ans.push_back(mapp[it]);
        }

        return ans;
    }
};