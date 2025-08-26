class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<pair<int, int>> nums;

        for(int i=0; i<dimensions.size(); i++){
            nums.push_back({(dimensions[i][0] *dimensions[i][0] + dimensions[i][1] * dimensions[i][1]) , i});
        }
        int maxi = -1;
        for(auto it : nums){
            if(it.first > maxi){
                maxi = it.first;
            }
        }
        vector<int> ans;
        for(auto it : nums){
            if(it.first == maxi) ans.push_back(dimensions[it.second][0] * dimensions[it.second][1]);
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};