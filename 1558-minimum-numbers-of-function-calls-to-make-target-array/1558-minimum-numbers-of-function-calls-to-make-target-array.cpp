class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;

        int check = 0;
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            while(nums[i] != 0){
                if(nums[i]%2 != 0) ans++; 
                cout<<nums[i]<<endl;
                nums[i] = nums[i]/2;
                if(nums[i] > 0) count++;
            }
            check = max(check,count);
        }
        return ans+check;
    }
};