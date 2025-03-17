class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;

        for(auto it : mapp){
            if(it.second%2 != 0 ) return false;
            cout<<it.second << " "<<mapp.size();
        }
        return true;
    }
};