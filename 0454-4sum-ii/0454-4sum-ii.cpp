class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<long long, long long> mapp;
        for(auto it : nums3){
            for(auto i : nums4){
                mapp[it+i]++;
            }
        }
        int count = 0;
        for(auto it : nums1){
            for(auto i : nums2){
                long long int sum = -(it+i);
                if(mapp.find(sum) != mapp.end()){
                    count += mapp[sum];
                }
            }
        }
        return count;
    }
};