class Solution {
private:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;

        int ans = 0;
        for(int i=0; i<=n; i++){
            while(!s.empty() && (i == n || nums[s.top()] >= nums[i])){
                auto it = s.top();
                s.pop();
                int height = nums[it];
                int width = 0;
                if(s.empty()){
                    width = i;
                }else{
                    width = i-s.top()-1;
                }
                ans = max(ans,height*width);
            }
            s.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> nums(matrix[0].size(),0);

        int ans = INT_MIN;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '1') nums[j]++;
                else nums[j] = 0;
            }
            int maxarea = largestRectangleArea(nums);
            ans = max(ans,maxarea);
        }
        return ans;
    }
};