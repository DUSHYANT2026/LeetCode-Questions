class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0; 
        int i = 0;
        int j = 0;

        while(j < n)
        {
           if( i != j && forts[i] != 0 && forts[j] != 0 )
            {
                if(forts[i] != forts[j])
                 ans = max(ans, j-i-1);
             i++;
            }
          while( i< j && forts[i] == 0)
           i++;

        j++;
        }
        return ans;
    }
};