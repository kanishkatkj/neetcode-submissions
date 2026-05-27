class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int breadth, length, amount;
        int maxAmount = 0;
        while(l < r){
            length = min(heights[l], heights[r]);
            breadth = r-l;
            amount = length * breadth;
            maxAmount = max(amount, maxAmount);
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxAmount;
    }
};
