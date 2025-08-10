class Solution {
public:
    bool reorderedPowerOf2(int x) {
        vector<int> nums;

        while(x != 0){
            nums.push_back(x%10);
            x = x/10;
        }
        
        sort(nums.begin(), nums.end());

        do{
            if (nums[0] == 0) {
                continue;
            }
            long long int n = 0;
            for(auto it : nums){
                n = (n*10) + it;
            }

            if (n > 0 && (n & (n - 1)) == 0) {
                return true;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        return false;
    }
};