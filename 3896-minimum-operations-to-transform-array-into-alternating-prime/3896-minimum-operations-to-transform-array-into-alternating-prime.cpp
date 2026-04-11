class Solution {
public:
    bool checkprime(int n){
        if(n <= 1) return false;

        for(int i = 2; i <= sqrt(n); i++){
           if(n % i == 0) return false;
        } 
        return true;
    }
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                while(!checkprime(nums[i])){
                    count++; nums[i]++;
                }
            }
            else{
                if(checkprime(nums[i])){
                    if(nums[i] == 2) count+=2;
                    else count++;
                }
            }
        }
        return count;
    }
};