class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> longestSubstr;
        int l = 0;
        int maxLength = 0;
        for(int r = 0; r < s.size(); r++){
            while(longestSubstr.find(s[r]) != longestSubstr.end()){
                longestSubstr.erase(s[l]);
                l++;
            }
            longestSubstr.insert(s[r]);
            maxLength = max(maxLength, r-l+1);
        }
        return maxLength;
    }
};
