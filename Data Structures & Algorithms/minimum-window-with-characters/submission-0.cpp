#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t.empty() || s.empty() || s.length() < t.length()) {
            return "";
        }

        // Count frequencies of characters in t
        std::unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }

        int required = tCount.size(); // Number of unique characters needed
        int formed = 0;              // Number of unique characters currently matching the required frequency
        
        std::unordered_map<char, int> windowCounts;
        
        // Window pointers and result tracking: {window length, left, right}
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (r < s.length()) {
            char c = s[r];
            windowCounts[c]++;

            // If the current character's frequency matches its required frequency in t
            if (tCount.count(c) && windowCounts[c] == tCount[c]) {
                formed++;
            }

            // Try and contract the window until it ceases to be 'valid'
            while (l <= r && formed == required) {
                c = s[l];

                // Update the smallest window found so far
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                // Character at the left pointer is about to be excluded from the window
                windowCounts[c]--;
                if (tCount.count(c) && windowCounts[c] < tCount[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};