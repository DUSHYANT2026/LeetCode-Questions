class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        int n = nums.size(); 
        int m = nums[0].size();

        for(int i=0; i<n; i++){
            unordered_map<char,int> row_map, col_map;
            for(int j=0; j<m; j++){
                if (nums[i][j] != '.'){
                    row_map[nums[i][j]]++;
                    if (row_map[nums[i][j]] > 1) return false;
                }
                if (nums[j][i] != '.'){
                    col_map[nums[j][i]]++;
                    if (col_map[nums[j][i]] > 1) return false;
                }
            }
        }
        unordered_map<char,int> box1, box2, box3, box4, box5, box6, box7, box8, box9;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(nums[i][j] != '.') {
                    box1[nums[i][j]]++;
                    if(box1[nums[i][j]] > 1) return false;
                }
            }
            for(int j=3; j<6; j++){
                if(nums[i][j] != '.') {
                    box2[nums[i][j]]++;
                    if(box2[nums[i][j]] > 1) return false;
                }
            }
            for(int j=6; j<9; j++){
                if(nums[i][j] != '.') {
                    box3[nums[i][j]]++;
                    if(box3[nums[i][j]] > 1) return false;
                }
            }
        }
        for(int i=3; i<6; i++){
            for(int j=0; j<3; j++){
                if(nums[i][j] != '.') {
                    box4[nums[i][j]]++;
                    if(box4[nums[i][j]] > 1) return false;
                }
            }
            for(int j=3; j<6; j++){
                if(nums[i][j] != '.') {
                    box5[nums[i][j]]++;
                    if(box5[nums[i][j]] > 1) return false;
                }
            }
            for(int j=6; j<9; j++){
                if(nums[i][j] != '.') {
                    box6[nums[i][j]]++;
                    if(box6[nums[i][j]] > 1) return false;
                }
            }
        }
        for(int i=6; i<9; i++){
            for(int j=0; j<3; j++){
                if(nums[i][j] != '.') {
                    box7[nums[i][j]]++;
                    if(box7[nums[i][j]] > 1) return false;
                }
            }
            for(int j=3; j<6; j++){
                if(nums[i][j] != '.') {
                    box8[nums[i][j]]++;
                    if(box8[nums[i][j]] > 1) return false;
                }
            }
            for(int j=6; j<9; j++){
                if(nums[i][j] != '.') {
                    box9[nums[i][j]]++;
                    if(box9[nums[i][j]] > 1) return false;
                }
            }
        }
        return true;
    }
};