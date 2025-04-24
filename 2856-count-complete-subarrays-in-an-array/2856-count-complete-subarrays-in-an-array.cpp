class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0;
        set<int>s;
        for(auto it : nums){
            s.insert(it);
        }
        for(int i=0; i<nums.size(); i++){
            set<int> news;
            for(int j=i; j<nums.size(); j++){
                news.insert(nums[j]);
                if(s == news)  count++;
            }
        }
        return count;
    }
};