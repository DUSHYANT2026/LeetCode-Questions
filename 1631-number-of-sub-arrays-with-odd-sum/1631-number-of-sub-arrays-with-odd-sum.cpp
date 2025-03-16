class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // int ans = 0; long long sum = 0; 
        // for(int i=0; i<arr.size(); i++){
        //     vector<int> nums;
        //     for(int j=i; j<arr.size(); j++){
        //         nums.push_back(arr[j]);
        //         for(auto it : nums){
        //             sum += it;
        //         }
        //         if(sum%2 == 1){
        //             ans++; sum = 0;
        //         }
        //     }
        // }
        // return ans%1000000007;
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1, ans = 0; 
        long long prefixSum = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 1) {  
                ans = (ans + evenCount) % MOD;
                oddCount++; 
            } else {  
                ans = (ans + oddCount) % MOD;
                evenCount++; 
            }
        }
        return ans;
    }
};



