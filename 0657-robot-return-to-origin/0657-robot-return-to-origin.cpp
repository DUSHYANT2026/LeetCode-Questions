class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> mapp;
        for(auto it : moves) mapp[it]++;
        int countl = 0; int countr = 0; int countu = 0; int countd = 0;
        for(auto it : mapp){
            if(it.first == 'L') countl = it.second;
            else if(it.first == 'R') countr = it.second;
            else if(it.first == 'U') countu = it.second;
            else countd = it.second;
        }
        if(countl > 0 && countu > 0){
             if(countl == countr && countl != 0 && countr != 0 && countu == countd && countu != 0 && countd != 0) return true;
        }
        else{
             if(countl == countr && countl != 0 && countr != 0 || countu == countd && countu != 0 && countd != 0) return true;
        }
        return false;
    }
};