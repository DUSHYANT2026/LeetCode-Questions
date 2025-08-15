class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string temp = "";
        for(auto it : path){
            if(it == '/'){
                if(!temp.empty()){
                    if(temp == "..."){
                        s.push(temp);
                        temp =  "";
                    }
                    else if(temp == ".."){
                        if(!s.empty()){
                            s.pop();
                        }
                        temp = "";
                    }
                    else if(temp == "."){
                        temp = "";
                    }
                    else{
                        s.push(temp);
                        temp = "";
                    }
                }
                else continue;
            }
            else{
                temp += it;
            }
        }
        if(!temp.empty()){
            // if(temp == "..") s.pop();
            if(temp != "." && temp != "..") s.push(temp);
        }

        string ans = "";
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return (ans.empty()) ? "/" : ans;
    }
};


// class Solution {
// public:
//     string simplifyPath(string path) {
        
//         vector<string> nums;
//         stringstream ss(path);
//         string temp = "";
//         while(ss >> temp){
//             nums.push_back(temp);
//         }
//         for(auto it : nums) cout<<it<<" ";
//         return "";
//     }
// };