// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();

//         long long ans = 0;
//         vector<int> v1 (n);
//         vector<int> v2 (n);

//         v1[0] = nums[0];
//         for(int i=1;i<n;i++){
//             v1[i] = max(v1[i-1],nums[i]);
//         }

//         v2[n-1] = nums[n-1];
//         for(int i=n-2;i>=0;i--){
//             v2[i] = max(v2[i+1],nums[i]);
//         }
//         for(int i=0;i<n-1;i++){
//             long long x = (long long)((v1[i]-nums[i])*v2[i+1]);
//             ans = max(ans,x);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int>suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
    
        for(int i=1;i<n;i++)
            pre[i]=max(pre[i-1],nums[i]);
        
        for(int i=n-2;i>=0;i--)
            suff[i]=max(suff[i+1],nums[i]);
        
        long long ans=0;
        for(int i=0;i<n-1;i++){
            long long temp=(long long)(pre[i]-nums[i])*suff[i+1];
            ans=max(temp,ans);
        }
        return ans;
    }
};