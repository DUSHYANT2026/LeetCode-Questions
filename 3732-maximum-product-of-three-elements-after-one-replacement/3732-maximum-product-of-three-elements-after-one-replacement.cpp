class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        vector<pair<long long,bool>> temp;

        for(auto it : nums){
            if(it >= 0) temp.push_back({it,true});
            else temp.push_back({abs(it),false});
        }
        sort(temp.begin(),temp.end());
        // for(auto it : temp){
        //     cout<<it.first<<" "<<it.second;
        //     cout<<endl;
        // }
        int n = nums.size();
        bool mark1 = temp[n-1].second;
        bool mark2 = temp[n-2].second;
        long long num1 = temp[n-1].first;
        long long num2 = temp[n-2].first;
        return num1*num2*1e5;
    }
};