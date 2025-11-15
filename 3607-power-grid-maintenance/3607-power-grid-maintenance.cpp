// class Solution {
// public:
//     void dfscheck(int node, vector<int> &vis, set<int>& temp, vector<int> graph[]){
//         vis[node] = 1;
//         for(auto it : graph[node]){
//             if(!vis[it]){
//                 dfscheck(it,vis,temp,graph);
//             }
//         }
//         temp.insert(node);
//     }
//     vector<int> processQueries(int n, vector<vector<int>>& nums, vector<vector<int>>& queries) {
//         vector<int> graph[n+1];
//         for(auto it : nums){
//             graph[it[0]].push_back(it[1]);
//             graph[it[1]].push_back(it[0]);
//         }
//         vector<int> vis(n+1,0);
//         vector<set<int>> check;

//         for(int i=1; i<=n; i++){
//             set<int> temp;
//             if(!vis[i]){
//                 dfscheck(i,vis,temp,graph);
//             }
//             if(!temp.empty()) check.push_back(temp);
//         }
//         int size = queries.size();
//         vector<int> ans;

//         for(auto it : check){

//             for(auto i : queries){
//                 vector<int> temp = i;
//                 if(i[0] == 1){
//                     if(it.find(i[1]) != it.end()){
//                         ans.push_back(i[1]);
//                     }
//                     else{
//                             if(!it.empty()){
//                                 auto x = it.begin();
//                                 ans.push_back(*x);
//                             }
//                             else{
//                                 ans.push_back(-1);
//                             }
//                     }
//                 }
//                 else{
//                     if(it.find(i[1]) != it.end()){
//                         it.erase(i[1]);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


class DisjointSet
{
public:
    vector<int> parent,size;

    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUParent(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findUParent(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int pu=findUParent(u),pv=findUParent(v);
        if(pu==pv)
            return;
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution
{
public:
    vector<int> processQueries(int n,vector<vector<int>>& connections,vector<vector<int>>& queries)
    {
        DisjointSet ds(n);
        for(auto it:connections)
        {
            int u=it[0],v=it[1];
            ds.unionBySize(u,v);
        }

        unordered_map<int,set<int>> compoMap;
        for(int i=1;i<=n;i++)
        {
            compoMap[ds.findUParent(i)].insert(i);
        }

        vector<int> ans;
        for(auto it:queries)
        {
            int type=it[0],node=it[1];
            set<int>& online=compoMap[ds.parent[node]];
            
            if(type==1)
            {
                if(online.find(node)!=online.end())
                    ans.push_back(node);
                else if(!online.empty())
                    ans.push_back(*online.begin());
                else
                    ans.push_back(-1);
            }
            else
            {
                online.erase(node);
            }
        }

        return ans;
    }
};