class Solution {
private:
    int check(int mid, vector<int> nums) {
            int total = 1;
            int curDist = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] - curDist >= mid) {
                    total++;
                    curDist = nums[i];
                }
            }
            return total;
        }
public:
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());

        if(m <= 1) return 0;
        if(m ==  2) return nums[nums.size()-1] - nums[0];
        int n = nums.size();
        int s = 0;
        int e = nums[n-1];
        int ans = 0;

        while(s <= e){
            int mid = (s+e)/2;
            if(check(mid,nums) >= m){
                ans = max(ans , mid);
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};