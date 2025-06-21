class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> mapp;
        for(auto it : s){
            mapp[it]++;
        }
        unordered_set<int> st;
        int count = 0;
        for(auto  it : mapp){
            int x = it.second;
            while(x > 0 && st.find(x) != st.end()){
                count++;
                x--;
            }
            st.insert(x);
        }
        return count;
    }
};