class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxi = 0;
        for(auto it : target) maxi = max(maxi, it);

        vector<vector<int>> nums;
        for(int i=0; i<triplets.size(); i++){
            vector<int> temp = triplets[i]; bool mark = false;

            for(auto it : temp){
                if(it > maxi) mark = true; 
            }
            if(mark == false) nums.push_back(temp);
        }

        vector<vector<int>> newnums;
        for(int i=0; i<3; i++){
            vector<int> temp;
            for(int j=0; j<nums.size(); j++){
                temp.push_back(nums[j][i]);
            }
            newnums.push_back(temp);
        }

        for(int i=0; i<3; i++){
            if(find(newnums[i].begin(),newnums[i].end() , target[i]) == newnums[i].end()) return false;
        }
        return true;
    }
};