class Solution {
public:
    bool check(vector<int> &nums){
        for(int i=1; i<nums.size(); i++) if(nums[i] <= nums[i-1]) return false;
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        if(k == 1 && nums.size() > 1) return true;
        
        for(int i=0; i<nums.size()-2*k; i++){
            vector<int> temp;
            int mark = 0;
            for(int j=i; j<i+k; j++){
                temp.push_back(nums[j]);
                mark = j+1;
            }
            if(check(temp)){
                if(mark + k < nums.size()){
                    vector<int> v;
                    for(int l=mark; l < mark+k; l++) v.push_back(nums[l]);
                    if(check(v)) return true;
                }
            }
        }
        return false;
    }
};