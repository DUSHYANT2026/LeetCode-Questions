class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]){
                if(count < k){
                    count++;
                    cout<<1<<" "<<endl;
                }
                else {cout<<2<<" "<<endl; nums.erase(nums.begin()+i); i--; }
            }
            else {cout<<3<<" "<<endl; count = 1;}
        }
        cout<<endl;
        for(auto it : nums) cout<<it<<" ";
        return nums;
    }
};