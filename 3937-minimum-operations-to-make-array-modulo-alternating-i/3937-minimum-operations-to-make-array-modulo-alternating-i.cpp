// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {

//         int count = INT_MAX;

//         for(int x = 0; x < k; x++){
//             for(int y = 0; y < k; y++){
//                 if(x == y) continue;

//                 int total = 0;

//                 for(int i = 0; i < nums.size(); i++){
//                     if(i % 2 == 0){                             
//                         int ini = 0; int dei = 0;
//                         int val = nums[i];                      
//                         while(val % k != x){ val++; ini++; }
//                         val = nums[i];                         
//                         while(((val%k)+k)%k != x){ val--; dei++; } 
//                         total += min(ini, dei);
//                     }
//                     else{
//                         int inj = 0; int dej = 0;
//                         int val = nums[i];
//                         while(val % k != y){ val++; inj++; }
//                         val = nums[i];
//                         while(((val%k)+k)%k != y){ val--; dej++; }
//                         total += min(inj, dej);
//                     }
//                 }
//                 count = min(count, total);
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;  

                int cost = 0;
                for (int i = 0; i < n; i++) {
                    int target = (i % 2 == 0) ? x : y; 
                    int cur = nums[i] % k;

                
                    int inc = (target - cur + k) % k;  
                    int dec = (cur - target + k) % k;  
                    cost += min(inc, dec);
                }

                ans = min(ans, cost);
            }
        }
        return ans;
    }
};