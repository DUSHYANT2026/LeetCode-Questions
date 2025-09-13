class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<int,int> mapp1, mapp2;

        for(auto it : s){
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') mapp1[it]++;
            else mapp2[it]++;
        }
        int count1 = 0; int count2 = 0;
        for(auto it : mapp1) count1 = max(count1,it.second);
        for(auto it : mapp2) count2 = max(count2,it.second);
        return count1 + count2;
    }
};