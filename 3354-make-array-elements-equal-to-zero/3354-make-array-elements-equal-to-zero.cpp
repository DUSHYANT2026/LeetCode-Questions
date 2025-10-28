class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0; int sum = 0; for(auto  it : nums) sum += it; int left = 0;
        for(auto it : nums){
            left += it;  sum -= it;
            if(it == 0){
                if(sum == left) ans += 2;
                else if(abs(sum-left) == 1) ans += 1; 
            }
        }
        return ans;
    }
};