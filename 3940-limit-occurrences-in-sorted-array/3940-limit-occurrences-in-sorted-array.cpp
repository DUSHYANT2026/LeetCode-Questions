class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]){
                if(count < k){
                    count++;
                }
                else{ nums.erase(nums.begin()+i); i--; }
            }
            else count = 1;
        }
        return nums;
    }
};