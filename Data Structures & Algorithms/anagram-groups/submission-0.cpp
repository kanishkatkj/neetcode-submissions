class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> Map;
        for(string i : strs){
            string sorted_str = i;
            sort(sorted_str.begin(), sorted_str.end());
            Map[sorted_str].push_back(i);
        }
        vector<vector<string>> result;
        for(auto& s : Map){
            result.push_back(s.second);
        }
        return result;
    }
};
