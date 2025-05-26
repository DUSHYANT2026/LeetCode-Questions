class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string,int> mapp;
        for(int i=0; i<list1.size(); i++) mapp[list1[i]] = i;

        vector<int> mark(list2.size(),-1);
        int temp = INT_MAX;
        for(int i=0; i<list2.size(); i++){
            int index = 0;
            if(mapp.find(list2[i]) != mapp.end()){
                index = i + mapp[list2[i]];
                if(temp > index){
                    temp = index;
                }
                mark[i] = index;
            }
        }

        for(int i=0; i<list2.size(); i++){
            if(mark[i] == temp){
                ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};