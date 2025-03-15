class Solution {
private:
    void dpcheck(set<vector<int>>& s, vector<int> &nums,vector<int> temp, int index){
        int n = nums.size();
        if(index == n){
            s.insert(temp);
            return;
        }

        temp.push_back(nums[index]);
        dpcheck(s,nums,temp,index+1);
        temp.pop_back();
        dpcheck(s,nums,temp,index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        dpcheck(s,nums,temp,0);
        for(auto it : s) ans.push_back(it);
        return ans;
    }
};