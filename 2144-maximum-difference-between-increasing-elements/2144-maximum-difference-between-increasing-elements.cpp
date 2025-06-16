// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int ans = 0;
//         for(int i=0; i<nums.size()-1;  i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(i < j)
//                 ans = max(ans , (nums[j] - nums[i]));
//             }
//         }
//         return ans == 0 ? -1 : ans;
//     }
// };


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size(),ans=0; vector<int> pre(n), suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++) pre[i]=min(pre[i-1],nums[i]);
        for(int i=n-2;i>=0;i--) suff[i]=max(suff[i+1],nums[i]);
        for(int i=0;i<n;i++) ans=max(ans,suff[i]-pre[i]);
        return ans == 0 ? -1 : ans;
    }
};