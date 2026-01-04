class Solution {
public:
    // int check(int num){
    //     int count = 1;
    //     int sum = num;
    //     for(int i=1; i<=num/2; i++){
    //         if(num%i == 0){
    //             count++;
    //             sum += i;
    //         }
    //     }
    //     if(count == 4) return sum;
    //     return 0;
    // }
    int check(int num){
        int count = 0;
        int sum = 0;
        for(int i=1; i*i <= num; i++){
            if(num%i == 0){
                count++;
                sum += i;
                if(i != num/i){
                   count++;
                   sum += num/i;
                }
                if(count > 4) return 0;
            }
        }
        if(count == 4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            ans += check(nums[i]);
        }
        return ans;
    }
};