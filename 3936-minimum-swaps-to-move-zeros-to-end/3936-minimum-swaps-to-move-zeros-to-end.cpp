class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count = 0; int ans = 0;
        for(int i=0; i<nums.size(); i++) { if(nums[i] == 0) count++; }
        for(int i=0; i<nums.size(); i++){
            if(nums[nums.size()-1 - i] != 0 && count > 0){
                ans++;
                count--;
            }
            else {
                if(count == 0) break;
                count--;
            }
        }
        return ans;
    }
};