class Solution {
public:
    int countCollisions(string nums) {
        int count = 0;
        stack<char> s;

        for(int i = 0; i < nums.size(); i++){
            char check = nums[i];
            if(!s.empty() && s.top() == 'R' && check == 'L'){
                count += 2;
                s.pop();
                check = 'S';
            }
            else if(!s.empty() && s.top() == 'S' && check == 'L'){
                count += 1;
                check = 'S';
            }
            while(!s.empty() && s.top() == 'R' && check == 'S'){
                count += 1;
                s.pop();
            }
            s.push(check);
        }
        return count;
    }
};