class Solution {
public:
    int canBeTypedWords(string text, string bl) {
        vector<string> nums;
        istringstream iss(text);
        string word;
        while(iss >> word) nums.push_back(word);

        int count = 0;
        for(int i=0;i<nums.size();i++){
            string x = nums[i];
            unordered_map<char,int> mapp;
            for(auto it : x){
                mapp[it]++;
            }
            bool mark = true;
            for(int j=0;j<bl.size();j++){
                if(mapp.find(bl[j]) != mapp.end()){
                    mark = false;
                    break;
                }
            }
            if(mark == true) count++;
        }
        return count;
    }
};