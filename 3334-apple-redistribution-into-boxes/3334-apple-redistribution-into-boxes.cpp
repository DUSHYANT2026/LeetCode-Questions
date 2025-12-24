class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count = 0;
        int sum = 0;
        for(auto it : apple){
            sum += it;
        }
        sort(capacity.rbegin(),capacity.rend());
        for(int i=0; i<capacity.size(); i++){
          
            sum -= capacity[i];
            count++;
            if(sum<=0)break;
        }
        return count;
    }
};
