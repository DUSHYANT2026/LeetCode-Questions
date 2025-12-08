class Solution {
public:
    long long maxPoints(vector<int>& x, vector<int>& y, int k) {
        long long sum = 0;
        for(auto it : x) sum += it;
        int n = x.size();
        vector<long long> nums(n,0);
        for(int i=0; i<x.size(); i++){
            if(y[i] > x[i]) nums.push_back(y[i] - x[i]);
        } 
        sort(nums.rbegin(),nums.rend());
        for(int i=0; i<n-k; i++){ sum += nums[i];}
        return sum;
    }
};