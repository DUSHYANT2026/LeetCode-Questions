class Solution {
private:
    void dfscheck(int index, int n, vector<int> &temp, vector<int> &nums, set<vector<int>> & ans){
        if(index == n){
            ans.insert(temp);
            return;
        }
        for(int i=index; i<n; i++){
            temp.push_back(nums[i]);
            swap(nums[index],nums[i]);
            dfscheck(index+1,n,temp,nums,ans);
            swap(nums[index],nums[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<int> temp;
        // dfscheck(0,nums.size(),temp,nums,s);
        // for(auto it : s) ans.push_back(it);
        do{
            s.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        for(auto it : s) ans.push_back(it);
        return ans;
    }
};