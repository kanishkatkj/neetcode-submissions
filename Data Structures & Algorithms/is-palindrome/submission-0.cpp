class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            while (l < r && !isalnum(static_cast<unsigned char>(s[l]))) {
                l++;
            }
            while(l < r && !isalnum(static_cast<unsigned char>(s[r]))){
                r--;
            }
            if (tolower(static_cast<unsigned char>(s[l])) != tolower(static_cast<unsigned char>(s[r]))) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
