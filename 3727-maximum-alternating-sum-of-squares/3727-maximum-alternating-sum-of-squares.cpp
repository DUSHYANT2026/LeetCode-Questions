class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for(int i=0; i<nums.size(); i++) nums[i] = abs(nums[i]);

        sort(nums.begin(),nums.end());

        long long sum1 = 0; long long sum2 = 0;

        int x = nums.size()/2;

        for(int i=0; i<nums.size(); i++){
            if(x > i) sum1 += (nums[i]*nums[i]);

            else sum2 += (nums[i]*nums[i]);
        }
        cout<<endl;
        cout<<sum1<<" "<<sum2<<endl;
        return sum2-sum1;
    }
};