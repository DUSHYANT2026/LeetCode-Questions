class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        vector<int> a=nums;
        int mini=INT_MAX;
        sort(a.begin(),a.end());
        int count=0;
        for(int i=a.size()-1; i>=0; i--){
            int point=ceil(a[i]/float(k));
            auto it=lower_bound(a.begin(),a.end(),point);
            int sub=it-a.begin();
            mini=min(mini,(sub+count));
            count++;
        }
        return mini;
    }
};