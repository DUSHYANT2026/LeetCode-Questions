class Solution {
public:
    int gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size(), g;
        int ones = 0, overallG = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1)
                ones++;
            overallG = gcd(overallG, nums[i]);
        }
        
        if(ones > 0)
            return n - ones;
        if(overallG > 1)
            return -1;

        int mini = n+1;
        for(int i = 0;i<n;i++){
            g = nums[i];
            for(int j = i+1;j<n;j++){
                g = gcd(g, nums[j]);
                if(g == 1){
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }
        return mini == n+1 ? -1 : n + mini - 2;
    }
};