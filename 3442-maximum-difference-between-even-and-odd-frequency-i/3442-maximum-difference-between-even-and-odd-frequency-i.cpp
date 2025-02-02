class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mapp;
        for(auto it : s) mapp[it]++;

        int ans = INT_MIN; int even = INT_MAX; int odd = INT_MIN;
        for(auto it : mapp){
            if(it.second%2 == 0){
                even = min(even,it.second);
            }else{
                odd = max(odd,it.second);
            }
        }
        return odd-even;
    }
};