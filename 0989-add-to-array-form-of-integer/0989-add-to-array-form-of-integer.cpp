// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& num, int k) {
//         long long n=0;
//         for(auto it :  num){
//              if (n > LLONG_MAX / 10) {
//                 break;
//             }
//             n=n*10+it;
//         }
//          if (k < 0) {
//             n -= abs(k);
//         } else {
//             n += k;
//         }
//         vector<int> ans;
//         while(n!=0){
//             ans.push_back(n%10);
//             n/=10;
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& nums, int k) {
  int n=nums.size();
        int i=n-1;
        int carry=0;
        vector<int> ans;
        while(i>=0)
        {
            int dig=k%10;
            k/=10;
            int sum=nums[i]+dig+carry;
            ans.push_back(sum%10);
            carry=sum/10;
            
            i--;
        }
        while(k)
        {
            int dig=k%10;
            k/=10;
            int sum=dig+carry;
            ans.push_back(sum%10);
            carry=sum/10;
        }
        if(carry>0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
  }
};