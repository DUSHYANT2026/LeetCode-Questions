class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        for(auto it : nums) s.insert(it);
        int ans = INT_MIN; int sum = 0;
        for(auto it : s){
            if(it > 0) sum += it;
            ans = max(ans,it);
        }
        return (ans < 0) ? ans : sum;
    }
};