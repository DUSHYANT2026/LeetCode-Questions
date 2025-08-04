class Solution {
public:
    int totalFruit(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        long long int ans = LONG_MIN;
        long long int count;
        for(int i=0; i<nums.size(); i++){
            set<int> mapp;
            count = 0;
            for(int j=i; j<nums.size(); j++){
                count++;
                mapp.insert(nums[j]);
                if(mapp.size() <= 2){
                    ans = max(ans,count);    
                }
            }
        }
        return (ans == INT_MIN) ? count : ans;
    }
};