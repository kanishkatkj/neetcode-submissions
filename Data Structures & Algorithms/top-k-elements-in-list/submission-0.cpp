class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> Map;
        for(int i = 0; i < n; i++){
            Map[nums[i]]++;
        }
        vector<pair<int,int>> res(Map.begin(), Map.end());
        sort(res.begin(), res.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        vector<int> result;
        for(const auto& pair : res){
            if(k == 0) break;
            result.push_back(pair.first);
            k--;
        }
        return result;
    }
};
