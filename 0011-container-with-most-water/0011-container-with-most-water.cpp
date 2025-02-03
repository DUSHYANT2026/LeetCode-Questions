class Solution {
public:
    int maxArea(vector<int>& height) {
     int s=0;
     int e=height.size()-1;
     int area =INT_MIN;
     while(s<=e){
        int h=min(height[s],height[e]);
        int l=e-s;
        area=max(area,(h*l));
        if(height[s]<height[e])
            s++;
            else
            e--;
        }
       return area;   
     }
};