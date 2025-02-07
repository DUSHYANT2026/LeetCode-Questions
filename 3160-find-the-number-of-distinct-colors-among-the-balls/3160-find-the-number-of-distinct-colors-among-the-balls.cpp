class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>color,ball;
        vector<int>ans;
        int cnt=0;
        for(auto it:queries){
            int b=it[0];
            int c=it[1];
            if(ball.count(b))
                if(--color[ball[b]]==0)
                    cnt--;
                ball[b]=c;
                if(++color[c]==1)
                    cnt++;
            
            ans.push_back(cnt);
        }
        return ans;
    }
};