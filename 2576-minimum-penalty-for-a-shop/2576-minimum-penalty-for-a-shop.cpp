class Solution {
public:
    int bestClosingTime(string nums) {
        int ans = INT_MAX;
        int sumy = 0;
        for(auto it : nums) if(it == 'y') sumy++;
    
        int sumx = 0;
        int index = -1;
        for(int i=0; i<=nums.size(); i++){
            long long sum = sumy + sumx;
            if(ans > sum){
                ans = sum;
                index = i;
            }
            if(i<nums.size()) if(nums[i] == 'N') sumx++;
            if(i<nums.size()) if(nums[i] == 'Y') sumy--;
        }
        return index;
    }
};