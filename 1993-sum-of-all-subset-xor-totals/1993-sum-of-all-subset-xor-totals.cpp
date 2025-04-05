class Solution {
private:
    void dpcheck(int i, int n, int &ans,vector<int> &temp, vector<int> &nums){
        if(i == n){
            int subsetsum = 0 ;
            for(auto it : temp){
                subsetsum ^= it;
            } 
            ans += subsetsum;
            return;
        }
        temp.push_back(nums[i]);
        dpcheck(i+1,n,ans,temp,nums);
        temp.pop_back();
        dpcheck(i+1,n,ans,temp,nums);

    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n  = nums.size(); int ans = 0;
        vector<int> temp;
        dpcheck(0,n,ans,temp,nums);
        return ans;
    }
};