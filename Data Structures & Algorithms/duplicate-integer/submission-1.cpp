class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++){
            numMap[nums[i]]++;
        }
        for(const auto& pair : numMap){
            if(pair.second > 1){
                return true;
            }
        }
        return false;
    }
};