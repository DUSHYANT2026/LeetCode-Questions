class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        if(k == 1){
            unordered_map<int,int> mapp;
            for(auto  it : nums) mapp[it]++;
            for(auto it : mapp){
                if(it.second == 1){
                    ans = max(ans,it.first);
                }
            }
        }
        else if(k == nums.size()){
            for(auto it : nums) ans = max(ans,it);
        }
        else{
            unordered_map<int,int> mapp;
            for(int i=0; i<=nums.size()-k; i++){
                for(int j=i; j<k+i; j++){
                    mapp[nums[j]]++;
                }
            }
            for(auto it : mapp){
                if(it.second == 1){
                    ans = max(ans,it.first);
                }
            }
        }
        return ans;
    }
};