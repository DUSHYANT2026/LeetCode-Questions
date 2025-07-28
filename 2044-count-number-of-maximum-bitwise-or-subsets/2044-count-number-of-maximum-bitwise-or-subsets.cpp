class Solution {
private:
    void recur(int index,int k,int &ans,int &subset,vector<int> & nums){
        if(index == nums.size()){
            if(ans == k){
                subset++;
            
            }
            return;
        }
        recur(index+1, k|nums[index] ,ans,subset,nums);
        recur(index+1, k,ans ,subset,nums);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int subset = 0;
        int ans = 0;
        for(auto it : nums){
            ans |= it;
        }
        recur(0,0,ans,subset,nums);
        return subset;
    }
};