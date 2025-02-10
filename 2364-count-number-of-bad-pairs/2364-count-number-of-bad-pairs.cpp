class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    //     long long count=0;
    //     int n= nums.size();
    //     for(int i=0;i<n-1;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(i<j && nums[i]-i != nums[j]-j){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
        long long n=nums.size();
        long long ans=((n*(n-1))/2);
        unordered_map<long long,long long>m;
        long long good=0;
        for(int i=0;i<n;i++){
            long long badpair=i-nums[i];
            if(m.count(badpair)) good+=m[badpair];
            m[badpair]++;
        }
        return ans-good;
    }
};

