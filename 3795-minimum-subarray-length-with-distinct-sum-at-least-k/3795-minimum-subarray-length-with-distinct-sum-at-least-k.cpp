class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        unordered_map<int,int> mapp;

        int j = 0; long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mapp[nums[i]]++;
            if(mapp[nums[i]] > 1 || (sum >= k)){
                while(mapp[nums[i]] > 1 || (sum >= k)){
                    if(mapp[nums[i]] == 1 && sum >= k)  ans = min(ans, i-j+1);
                    mapp[nums[j]]--;
                    sum -= nums[j];
                    j++;
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};