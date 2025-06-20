class Solution {
public:
    int maxDistance(string s, int k) {
        int lat=0;
        int lon=0;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char it=s[i];
            if(it=='N')
                lat++;
            else if(it=='S')
                lat--;
            else if(it=='E')
                lon++;
            else 
                lon--;
        
        ans=max(ans,min(abs(lat)+abs(lon)+(k*2),i+1));
        }
        return ans;
    }
};