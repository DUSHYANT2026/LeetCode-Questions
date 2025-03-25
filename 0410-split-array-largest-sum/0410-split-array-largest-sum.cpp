// class Solution {
// public:
//     int splitArray(vector<int>& nums, int k) {
//       int s = 0;
//       int e = 0;
//       for(auto it : nums){
//           s = max(s,it);
//           e += it;
//       }
//       while(s<e){
//           int mid = s+(e-s)/2;
//           int sum = 0;
//          int count = 1;
//           for(auto it : nums){
//               if(sum + it > mid){
//                   sum = it;
//                   count++;
//               }
//               else{
//                   sum += it;
//               }
//           }
//           if(count > k){
//               s = mid+1;
//           }
//           else{
//               e = mid;
//           }
//       }
//       return s;
//     }
// };

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSubArraySum) {
        int currSum = 0;
        int count = 1;
        for (int num : nums) {
            currSum += num;
            if (currSum > maxSubArraySum) {
                count++;
                currSum = num;
                if (count > k) {
                    return false;
                }
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
        // int n = nums.size();
        // sort(nums.begin(),nums.end());

        // if(k==2){
        //     return (nums[n-1] + nums[n-2]);
        // }
        // int sum1 = 0;
        // int sum2 = 0;
        // int arrSize = n/k;
        // int p;
        // vector<int> nums1;
        // vector<int> nums2;
        // if(n%2 != 0){
        //     p = arrSize+1;
        // }
        // else{
        //     p = arrSize;
        // }
        // while(k>2){
        //     for(int i = 0;i<arrSize;i++){
        //         nums1.push_back(nums[i]);
        //     }
        //     for(int i = arrSize;i<n;i++){
        //         nums2.push_back(nums[i]);
        //     }
        //     for(int i = 0;i<arrSize;i++){
        //         sum1 += nums1[i];
        //         sum2 += nums2[i];
        //     }
        // }
        // return min(sum1,sum2);
    }
};




