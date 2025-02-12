class Solution {
private:
    int checksum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, priority_queue<int>> mapp;

        for (int i = 0; i < nums.size(); i++) {
            int dsum = checksum(nums[i]);
            mapp[dsum].push(nums[i]);
        }
        for (auto it : mapp) {
            auto pq = it.second;
            int sum = 0;
            if(pq.size() >= 2){
               sum += pq.top(); pq.pop();
               sum += pq.top(); pq.pop();
               ans = max(ans, sum);
            }
        }
        return ans;
    }
};