class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        arr1.push_back(nums[0]);
        
        vector<int> arr2;
        arr2.push_back(nums[1]);
        
        int n = nums.size() - 2;
        
        int i = 2;
        
        while(n--) {
            
            if(arr1.back() > arr2.back()) 
                arr1.push_back(nums[i++]);
        
            else
                arr2.push_back(nums[i++]);
        }
        
        for(auto it : arr2)
            arr1.push_back(it);
    
        return arr1;
    }
};