class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<char,int> mapp;
        for(auto it : votes){
            for(int i=0; i<it.size(); i++){
                mapp[it[i]] += i;
            }
        }
        vector<pair<int,int>> v;
        for(auto it : mapp) v.push_back({it.second,it.first});
        auto compare = [](pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };
        sort(v.begin(),v.end(),compare);
        string ans  = "";
        for(auto it : v) ans += it.second;
        return ans;
    }
};