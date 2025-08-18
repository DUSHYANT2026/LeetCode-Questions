class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans = 0;
        int i=0; int j=0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums2[j] >= nums1[i]){
                ans++; i++; j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};