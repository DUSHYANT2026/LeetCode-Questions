class Solution {
public:
    bool check(vector<int>& nums, int i, int j, int target){
        unordered_map<int,int> mapp;
        int n = abs(j-i+1);
        for(int x = i; x <=j; x++)  mapp[nums[x]]++;
        for(auto it : mapp){
            if(it.first == target){
                if(it.second > n/2)
                return true;
            }
        }
        return false;
    }
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                if(check(nums,i,j,target)) count++;
            }
        }


        // temp
        // for(int i=0; i<nums.size(); i++){

        // }
        return count;
    }
};