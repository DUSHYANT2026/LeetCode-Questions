class Solution {
public:
    int par[26]; 
    int findpar(int node){
        if(par[node] == -1) return node;
        return par[node] = findpar(par[node]);
    }
    void unionfind(int x, int y){
        x = findpar(x);
        y = findpar(y);
        if(x != y){
            par[max(x,y)] = min(x,y);
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(par,-1,sizeof(par));
        for(int i=0; i<s1.size(); i++) unionfind(s1[i]-'a',s2[i]-'a');
        string ans = "";
        for(auto it : baseStr) ans += findpar(it-'a') + 'a';
        return ans;
    }
};