class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int heightIdx = st.top();
                st.pop();
                int height = heights[heightIdx];
                int width = st.empty() ? i : i - st.top() -1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        heights.pop_back();
        return maxArea;
    }
};
