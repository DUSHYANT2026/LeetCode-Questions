class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        sort(nums.begin(), nums.end(), greater<int>()); 
        vector<bool> used(nums.size(), false);
        return backtrack(nums, k, target, 0, 0, used);
    }

private:
    bool backtrack(vector<int>& nums, int k, int target, int currentSum, int start, vector<bool>& used) {
        if (k == 1) return true; 
        if (currentSum == target) {
            return backtrack(nums, k - 1, target, 0, 0, used); 
        }
        for (int i = start; i < nums.size(); ++i) {
            if (!used[i] && currentSum + nums[i] <= target) {
                used[i] = true;
                if (backtrack(nums, k, target, currentSum + nums[i], i + 1, used)) {
                    return true;
                }
                used[i] = false;
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
            }
        }
        return false;
    }
};