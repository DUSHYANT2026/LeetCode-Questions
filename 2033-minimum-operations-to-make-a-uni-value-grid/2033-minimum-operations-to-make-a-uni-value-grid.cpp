class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();  int m=grid[0].size();
        if(n==1 && m==1) return 0;
        
        vector<int> nums;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                nums.push_back(grid[i][j]);
            }
        }
        
        sort(nums.begin(),nums.end());
        int target=nums[nums.size()/2];
        int count=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==target) continue;               
                int rem=abs(target-grid[i][j]);
                if(rem%x != 0) return -1;                
                rem=rem/x;                
                if(rem == 0) count += 1;
                else count += rem;
            }
        } 
        return count;
    }
};