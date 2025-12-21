class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> mapp;
        for(int i=0; i<s.size(); i++){
            mapp[s[i]] += cost[i]; 
        }
        vector<pair<long long,char>> nums;
        for(auto it : mapp){
            nums.push_back({it.second, it.first});
        }
        sort(nums.rbegin(),nums.rend());
        long long ans = 0;
        nums.erase(nums.begin());
        for(auto it : nums) ans += it.first;
        return ans;
    }
};