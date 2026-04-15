class Solution {
public:
    int closestTarget(vector<string>& words, string target, int sindex) {
        vector<int> nums;
        for(int i=0; i<words.size(); i++){
            if(words[i] == target){
                nums.push_back(i);
            }
        }
        if(nums.size() == 0) return -1;

        int ans = INT_MAX; int n = words.size();
        for(auto it : nums){
            ans = min(ans, abs(sindex - it)%n);
            ans = min(ans, abs(abs(sindex - it) - n)%n);
        }
        return ans;
    }
};