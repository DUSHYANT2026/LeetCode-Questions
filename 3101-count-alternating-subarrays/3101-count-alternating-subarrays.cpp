class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long count = 0 ;

        for(int i=0; i<nums.size()-1;  i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j-1] != nums[j]){
                    count++;
                }else break;
            }
        }
        return count + nums.size();
    }
};