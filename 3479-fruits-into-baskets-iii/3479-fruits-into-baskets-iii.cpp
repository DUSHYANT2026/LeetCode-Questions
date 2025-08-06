class Solution {
public:
    int numOfUnplacedFruits(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp = nums2;
        int count = 0;
        for(int i=0; i<nums1.size(); i++){
            int mark = -1;
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] <= nums2[j]){
                    mark = j; break;
                }
            }
            cout<<mark<<endl;
            if(mark != -1) nums2.erase(nums2.begin()+mark);
        }
        return nums2.size();
    }
};