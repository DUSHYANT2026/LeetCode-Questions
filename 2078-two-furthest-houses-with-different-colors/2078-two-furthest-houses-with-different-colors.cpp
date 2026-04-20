class Solution {
public:
    int maxDistance(vector<int>& nums) {
        // int n=colors.size();
        int ans=INT_MIN;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(colors[i] != colors[j]){
        //             ans=max(ans,abs(j-i));
        //         }
        //     }
        // }
        int i=0; int j = nums.size()-1;
        while(i < j){
            if(nums[i] != nums[j]){
                ans = max(ans, (j-i));
            }
            i++;
        }
        int k =0 ; int l = nums.size()-1;
        while(k < l){
            if(nums[k] != nums[l]){
                ans = max(ans, (l-k));
            }
            l--;
        }
        return  ans;
    }
};