class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        if(nums.size() <= 2) return nums;
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size()-1; i++){
            int x = nums[i];
            bool mark = true;
            bool mark1 = true;

            for(int j=0; j<i; j++){
                if(nums[j] >= x) mark = false;
            }

            for(int k=i+1; k<nums.size(); k++){
                if(nums[k] >= x) mark1 = false;
            }

            if(mark  || mark1){ ans.push_back(x); cout<<i<<endl;}
        }

        ans.push_back(nums[nums.size()-1]);
        return ans;
    }
};