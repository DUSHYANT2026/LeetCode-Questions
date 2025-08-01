class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        set<vector<int>> s;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int k = j+1; int l = n-1;
                while(k < l){
                    long long int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        s.insert({nums[i] , nums[j] , nums[k] , nums[l]});
                        k++; l--;
                    }
                    else if((sum)< target) k++;
                    else l--;
                }
            }
        }
        for(auto it : s) ans.push_back(it);
        return ans;
    }
};