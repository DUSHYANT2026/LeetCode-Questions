class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int index = 0;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                index = i;
            }
        }
        long long sum = 0; long long sum2 =0;
        for(int i=0; i<=index; i++) sum+= nums[i];
        for(int i=index; i<nums.size(); i++) sum2+=nums[i];
        if(sum == sum2) return -1;
        if(sum > sum2) return 0;
        return 1; 
    }
};