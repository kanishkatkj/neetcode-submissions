class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // If s1 is longer than s2, it's impossible for s2 to contain a permutation of s1
        if (n1 > n2) return false;
        
        // Frequency arrays for s1 and the current window in s2
        std::vector<int> s1_count(26, 0);
        std::vector<int> s2_count(26, 0);
        
        // Count frequencies for the first window
        for (int i = 0; i < n1; ++i) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        
        // If the first window matches, we are done
        if (s1_count == s2_count) return true;
        
        // Slide the window across s2
        for (int i = n1; i < n2; ++i) {
            // Add the new character entering the window
            s2_count[s2[i] - 'a']++;
            
            // Remove the old character leaving the window
            s2_count[s2[i - n1] - 'a']--;
            
            // Compare the frequency arrays
            if (s1_count == s2_count) {
                return true;
            }
        }
        
        return false;
    }
};
