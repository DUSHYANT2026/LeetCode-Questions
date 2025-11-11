class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        auto custom =[](string a, string b){
            return a.size() < b.size();
        };
        sort(strs.begin(),strs.end(),custom);
        int count = 0;
        
        for(auto it : strs){
            int count0 = 0; int count1 = 0;
            for(auto i : it){
                if(i == '1') count1++;
                else count0++;
            }
            if(n >= count1 && m >= count0){
                count++;
                n -= count1;
                m -= count0;
            }
            else{
                break;
            }
        }
        return count;
    }
};