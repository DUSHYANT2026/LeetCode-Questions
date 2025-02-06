class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mapp[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto it : mapp){
            ans += (it.second*(it.second-1)/2) * 8;
        }
        return ans;
    }
};