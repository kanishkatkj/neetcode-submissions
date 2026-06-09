class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size() || s.empty() || t.empty()){
            return "";
        }
        vector<int> tCount(128, 0);
        vector<int> window(128, 0);
        for(char c : t){
            tCount[c]++;
        }
        int need = 0;
        int have = 0;
        for(int count : tCount){
            if(count > 0) need++;
        }
        int minLen = INT_MAX;
        int startIdx = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            window[c]++;
            if(tCount[c] > 0 && window[c] == tCount[c]) have++;
            while(have == need){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    startIdx = l;
                }
                char leftChar = s[l];
                window[leftChar]--;
                if(tCount[leftChar] > 0 && window[leftChar] < tCount[leftChar]) have--;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
