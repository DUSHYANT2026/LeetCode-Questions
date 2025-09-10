// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
        
//         vector<string> nums;
//         sort(words.begin(),words.end());
//         do{
//             string temp = "";
//             for(auto it : words) temp += it;
//             nums.push_back(temp);
//         }while(next_permutation(words.begin(),words.end()));


//        vector<int> ans;
//        for(auto it : nums) {
//            int pos = s.find(it, 0);
//            while(pos != string::npos){
//                 ans.push_back(pos);
//                 pos = s.find(it, pos + 1);
//             }
//         }
//         return ans;
//     }
// };





class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n=words.size();
        int m=words[0].size();
        int total=n*m;
        if(s.size()<total){
            return ans;
        }
        for(int i=0;i<=s.size()-total;i++){
            unordered_map<string,int>mp;
            
            for(int j=0;j<words.size();j++){
                mp[words[j]]++;
            }
            int k;
            for(k=0;k<n;k++){
                
                string temp=s.substr(i+k*m,m);
                // cout<<temp<<" "<<i<<endl;
                if(mp.count(temp)==0){
                    break;
                }
                else{
                    if(mp[temp]!=0){
                        mp[temp]--;
                    }
                    else{
                        break;
                    }
                }
            }
            if(k==n){
                ans.push_back(i);
            }
            
        }
        return ans ;
    }
};