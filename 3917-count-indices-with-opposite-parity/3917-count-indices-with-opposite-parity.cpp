class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int odd = 0; int even = 0;

        for(int i=nums.size()-1; i >= 0; i--){
            if(nums[i]%2 == 0){
                ans[i] = odd;
                even++; 
            }else{
                ans[i] = even;
                odd++;
            }
        }
        // for(int i=0; i<nums.size(); i++){
        //     int odd = 0; int even = 0;
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[j]%2 == 0) even++;
        //         else odd++;
        //     }
        //     if(nums[i]%2 == 0){
        //         ans[i] = odd;
        //     }
        //     else ans[i] = even;
        // }
        return ans;
    }
};