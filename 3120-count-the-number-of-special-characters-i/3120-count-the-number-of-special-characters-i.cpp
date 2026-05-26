class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<char> up; set<char> lo;
        for(auto it : word){
            if(islower(it)){
                lo.insert(it);
            }else{
                up.push_back(it);
            }
        }
        vector<char> nums;
        for(auto it : up){
            it = tolower(it);
            nums.push_back(it);
        }
        int count = 0;
        unordered_map<char,int> mapp;
        for(auto it : nums) mapp[it]++;

        for(auto it : lo){
            if(mapp.find(it) != mapp.end()){
                count++;
            }
        }
        return count;
    }
};