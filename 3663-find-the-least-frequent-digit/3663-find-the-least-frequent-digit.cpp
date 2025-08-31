class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int> mapp;
        while(n != 0){
            mapp[n%10]++;
            n/=10;
        }
        int ans = INT_MAX;
        int mini = INT_MAX;
        for(auto  it : mapp){
            if(it.second < mini){
                mini = it.second;
            }
        }
        for(auto it : mapp){
            if(it.second == mini){
                if(ans > it.first){
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};