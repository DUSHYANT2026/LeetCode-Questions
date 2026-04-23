class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n,0);
        unordered_map<int, vector<int>> mapp;
        
        for(int i=0; i<n; i++) mapp[nums[i]].push_back(i);
        
        for(auto [val, temp] : mapp) {
            if(temp.size() == 1) continue;
            int m = temp.size();
            long long sum = 0;
            
            for(int it : temp) sum += it;
            
            long long lsum = 0;
            for(int j=0; j<m; j++) {
                int it = temp[j];
                long long rsum = sum -lsum-it;       
                ans[it] = (long long)j*it-lsum+rsum - (long long)(m-j-1)*it;
                lsum += it;
            }
        }
        return ans;
    }
};