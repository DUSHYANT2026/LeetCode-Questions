class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(auto it : queries){
            for(auto i : dictionary){
                int count = 0;
                for(int x = 0; x<i.size();  x++){
                    if(it[x] != i[x]) count++;
                }
                if(count <= 2){ ans.push_back(it); break;};
            }
        }
        return ans;
    }
};