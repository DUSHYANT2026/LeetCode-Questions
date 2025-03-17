class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        int n =nums.size();
        for(int i=0; i <= k && i < n; i++){
            mapp[nums[i]]++;
            if(mapp[nums[i]] > 1) return true;
        }
        
        for(int i=1; i<n-k; i++){
            mapp[nums[i-1]]--;
            mapp[nums[i+k]]++;
            
            if(mapp[nums[i-1]] == 0) mapp.erase(nums[i-1]);
            if(mapp[nums[i+k]] > 1) return true;
        }
        return false;
    }
};



// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> mapp;
//         int n = nums.size();
        
//         // Handle edge case where k is larger than the array size
//         if (k >= n) {
//             k = n - 1;
//         }
        
//         // Initialize the map with the first k+1 elements
//         for (int i = 0; i <= k && i < n; i++) {
//             mapp[nums[i]]++;
//             if (mapp[nums[i]] > 1) return true;
//         }
        
//         // Slide the window through the array
//         for (int i = 1; i < n - k; i++) {
//             // Remove the element that is left behind by the window
//             mapp[nums[i-1]]--;
//             if (mapp[nums[i-1]] == 0) {
//                 mapp.erase(nums[i-1]);
//             }
            
//             // Add the new element that enters the window
//             mapp[nums[i+k]]++;
//             if (mapp[nums[i+k]] > 1) return true;
//         }
        
//         return false;
//     }
// };