class Solution {
public:
    int check(int mid, vector<int> &nums){
        int count = 1;
        int temp = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - temp >= mid){
                count++;
                temp = nums[i];
            }
        }
        return count;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int s = 0; int e = 1e9; int ans = 0;

        while(s <= e){
            int mid = (e+s)/2;
            if(check(mid,price) >= k){
                ans = max(ans, mid);
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};