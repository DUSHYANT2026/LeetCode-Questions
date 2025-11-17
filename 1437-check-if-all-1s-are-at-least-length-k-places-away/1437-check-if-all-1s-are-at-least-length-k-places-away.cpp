class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;

        int x = 0;
        if(nums[x] == 0){
            for(x = 0; x<nums.size(); x++){
                if(nums[x] == 1) break;
            }
        }
        for(int i = x+1; i<nums.size(); i++){
            if(nums[i] == 0){
                count++;
            }
            else{
                cout<<count<<endl;
                if(count < k) return false;
                count = 0;
            }
        }
        return true;
    }
};