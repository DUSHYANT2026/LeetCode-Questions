class Solution {
public:
    int possibleStringCount(string word) {
        // unordered_map<char,int> mapp; for(auto it : word) mapp[it]++;
        // int ans = 0; int count = 0;
        // for(auto it : mapp){ if(it.second > 1){ count++; ans += it.second-1;}}
        // return (ans == 0) ? 1 : (ans+count);
        int count = 1;
        for(int i=1; i<word.size(); i++){
            if(word[i-1] == word[i]) count++;
        }
        return count;
    }
};