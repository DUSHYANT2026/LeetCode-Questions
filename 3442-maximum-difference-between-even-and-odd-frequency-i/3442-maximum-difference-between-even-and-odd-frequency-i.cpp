class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mapp;
        for(auto it : s) mapp[it]++;
        int odd = INT_MIN; int even = INT_MAX;
        for(auto it : mapp){
            if(it.second%2 == 1) odd = max(odd,it.second);
            if(it.second%2 == 0) even = min(even,it.second);
        }
        return odd - even;
    }
};