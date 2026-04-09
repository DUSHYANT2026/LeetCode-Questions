class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i] > nums[s.top()]){
                int index = s.top(); s.pop();
                ans[index] = i-index;
            }
            s.push(i);
        }
        return ans;
    }
};