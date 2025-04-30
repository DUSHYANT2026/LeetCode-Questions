class Solution {
private:
    vector<int> check(int n){
        vector<int> ans;
        while(n!=0){
            ans.push_back(n%10); 
            n/=10;
        }
        return ans;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            vector<int> ans = check(nums[i]);
            if(ans.size() % 2 == 0){
                count++;
            }
        }
        return count;
    }
};