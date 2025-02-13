class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      
//         int n = nums.size();           
//         if(n < 2) return 0;
        
//         int count = 0;
        
//         vector<long long> ans;
//         for(auto it : nums){
//             ans.push_back((long long)it);
//         }

        
//         while(n > 0){
//              sort(ans.rbegin(),ans.rend());
            
//             if(ans[n-1] >= k){
//                 break;
//             }else{
//                 long long x = ans[n-1];
//                 long long y = ans[n-2];
//                 ans.pop_back();
//                 ans.pop_back();
                
//                 long long num = static_cast<long long>(min(x, y)) * 2LL + max(x, y);
    
//                 ans.push_back(num);
//                 count++;
//             }
//             n--;
//         }
//         return count;
    
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(auto it : nums){
            pq.push(it);
        }
        
        int count = 0;

        while(!pq.empty() && pq.top() < k) {
             if (pq.size() < 2) return count;
             long long x = pq.top();
             pq.pop();
             long long y = pq.top();
             pq.pop();
             long long num = static_cast<long long>(min(x, y)) * 2LL + max(x, y);
             pq.push(num);
             count++;
       }
        return count;
    }
};