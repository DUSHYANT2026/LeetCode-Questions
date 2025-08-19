class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count =  0;
        unordered_map<long long,long long> mapp;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                count++;
                mapp[count]++;
            }
            else{
                count = 0;
            }
        }
        long long ans = 0;
        for(auto it : mapp) ans += it.first*it.second;
        return ans;
    }
};