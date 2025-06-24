class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans; int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == key){
                for(int j = max(0,(i-k)); j<=min(n-1,(k+i)); j++) ans.insert(j);
            }
        }
        vector<int> v(ans.begin(),ans.end());
        return v;
    }
};