class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1 , 0),sur(n+1,0);
        int count = 0; int pount = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                count++;
            }
            if(nums[n-1-i] == 1){
                pount++;
            }
            sur[n-i-1] = pount;
            pre[i+1] = count;
        }
        int maxi = INT_MIN; int index = 0;
        for(int i=0; i<=n; i++) maxi = max(maxi, (sur[i]+pre[i]));

        vector<int> ans;
        for(int i=0; i<=n; i++){
            if(maxi == (sur[i]+pre[i])){
                ans.push_back(i);
            }
        }
        return ans;
    }
};