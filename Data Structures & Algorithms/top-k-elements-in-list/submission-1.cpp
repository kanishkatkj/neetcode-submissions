class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++){
            numMap[nums[i]]++;
        }
        vector<int> output;
        for(int i = 0; i < k; i++){
            auto maxVal = max_element(numMap.begin(), numMap.end(), [](const pair<int, int>&   a, const pair<int, int>& b){ 
            return a.second < b.second;
            }
        );
            output.push_back(maxVal->first);
            numMap.erase(maxVal);
        }
        return output;
    }
};
