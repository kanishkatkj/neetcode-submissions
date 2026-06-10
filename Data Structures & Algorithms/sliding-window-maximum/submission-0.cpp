class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int> res;
        vector<int> window;
        for(int i = 0; i < k; i++){
            window.push_back(nums[i]);
        }
        for(int i = k; i < n; i++){
            res.push_back(*max_element(window.begin(), window.end()));
            window.erase(window.begin());
            window.push_back(nums[i]);
        }
        res.push_back(*max_element(window.begin(), window.end()));
        return res;
    }
};
