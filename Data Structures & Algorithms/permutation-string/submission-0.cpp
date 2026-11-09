class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m) {
            return false;
        }

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // Count characters in s1 and first window of s2
        for (int i = 0; i < n; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // Check first window
        if (count1 == count2) {
            return true;
        }

        // Slide the window
        for (int i = n; i < m; i++) {

            // Add incoming character
            count2[s2[i] - 'a']++;

            // Remove outgoing character
            count2[s2[i - n] - 'a']--;

            // Compare frequencies
            if (count1 == count2) {
                return true;
            }
        }

        return false;
    }
};