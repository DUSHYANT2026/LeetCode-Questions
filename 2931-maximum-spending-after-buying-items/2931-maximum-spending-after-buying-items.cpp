class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;

        vector<int> nums;
        for(auto  it : values){
            for(auto i : it) nums.push_back(i);
        }
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            ans += (long long)nums[i]*(i+1) ; 
        }
        return ans;
    }
};