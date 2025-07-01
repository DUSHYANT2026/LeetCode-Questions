class Solution {
public:
    long long calculateScore(vector<string>& nums, vector<int>& values) {
        int n = nums.size(); long long ans = 0;
        vector<int> vis(n,0);

        for(int i=0; i<nums.size(); i++){
            if(vis[i] == 0){
                vis[i] = 1;
                // i = i%n;
                if(nums[i] == "jump"){
                    i = (i + values[i]-1);
                }else if(nums[i] == "add"){
                    ans += values[i];
                }
            }
            // else return ans;
        }
        return ans;
    }
};