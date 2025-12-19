class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        
        long long sum = 0;
        for(int i=0; i<k; i++) sum += arr[i];
        if(sum/k >= threshold) count++;

        for(int i=k; i<arr.size(); i++){
            long long newsum = sum - arr[i-k] + arr[i];
            cout<<sum<<" "<<newsum<<" "<<arr[i-k]<<" "<<arr[i]<<endl;
            if(newsum/k >= threshold) count++;
            sum = newsum;
        }
        return count;
    }
};