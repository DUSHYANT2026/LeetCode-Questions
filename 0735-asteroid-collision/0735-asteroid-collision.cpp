class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ans;
        
        for(int i = 0; i < asteroids.size(); i++) {
            int current = asteroids[i];
            
            while (!ans.empty() && ans.top() > 0 && current < 0) {
                int top = ans.top();
                ans.pop();
                if (top == -current) {
                    current = 0;
                    break;
                } else if (top > -current) {
                    current = top;
                }
            }
            if (current != 0) {
                ans.push(current);
            }
        }
        vector<int> a(ans.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            a[i] = ans.top();
            ans.pop();
        }
        return a;
    }
};