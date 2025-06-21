class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;}
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mpp;
        for(auto it:word)
            mpp[it]++;
        vector<int>v;
        for(auto it:mpp)
            v.push_back(it.second);
        int ans=INT_MAX;
        int n=v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int range=v[i]+k;
            int total=v[i];
            for(int j=i+1;j<n;j++){
                if(v[j]>range)
                    total+=range;
                else 
                    total+=v[j];
            }
            ans=min(ans,word.size()-total);
        }
        return ans;
    }
};