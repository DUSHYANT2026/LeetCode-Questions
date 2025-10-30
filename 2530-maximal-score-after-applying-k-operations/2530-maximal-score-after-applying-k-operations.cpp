class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<double> pq;
        for(auto it : nums) pq.push(it);

        while(!pq.empty() && k--){
            double it = pq.top(); pq.pop(); 
            ans += it;
            
            pq.push(ceil((it)/3.0));
        }
        return ans;
    }
};