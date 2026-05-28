class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int l = 0;
        int r = n-1;
        int lMax = 0;
        int rMax = 0;
        int totalWater = 0;
        while(l < r){
            if(height[l] < height[r]){
                if(height[l] >= lMax){
                    lMax = height[l];
                }
                else{
                    totalWater += lMax - height[l];
                }
                l++;
            }
            else{
                if(height[r] >= rMax){
                    rMax = height[r];
                }
                else{
                    totalWater += rMax - height[r];
                }
                r--;
            }
        }
        return totalWater;
    }
};
