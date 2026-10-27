#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // If lengths differ, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Frequency array for 26 lowercase English letters
        std::vector<int> count(26, 0);
        
        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        // Check if all counts are zero
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        
        return true;
    }
};