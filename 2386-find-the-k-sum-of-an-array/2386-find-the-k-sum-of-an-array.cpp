class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long maxSum = 0;
        vector<long long> absNums;
        
        for (int x : nums) {
            if (x > 0) maxSum += x;
            absNums.push_back(abs((long long)x));
        }
        
        sort(absNums.begin(), absNums.end());
        
        if (k == 1) return maxSum;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({absNums[0], 0});
        
        long long currentLoss = 0;
        for (int i = 0; i < k - 1; ++i) {
            auto [loss, idx] = pq.top();
            pq.pop();
            
            currentLoss = loss;
            
            if (idx + 1 < absNums.size()) {
                pq.push({loss + absNums[idx + 1], idx + 1});
                pq.push({loss - absNums[idx] + absNums[idx + 1], idx + 1});
            }
        }
        
        return maxSum - currentLoss;
    }
};