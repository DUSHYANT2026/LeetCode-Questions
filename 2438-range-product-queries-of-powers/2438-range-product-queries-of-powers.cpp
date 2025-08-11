class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> nums;
        if(n <= 2) return {n}; 

        if(n%2 != 0){
            n = n+1;
        } 

        while(n != 1){
            nums.push_back(n/2);
            n = n/2;
        }

        reverse(nums.begin(),nums.end());
        for(auto it : nums) cout<<it<<" ";

        vector<int> ans;

        for(auto it : queries){
            long long int sum = 1;
            if(it[0] < nums.size() && it[1] < nums.size()){
                for(int i=it[0]; i<=it[1]; i++){
                    sum *= nums[i];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};