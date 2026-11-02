class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int x : st) {

            // Check whether x is the start of a sequence
            if (st.find(x - 1) == st.end()) {

                int current = x;
                int count = 1;

                // Expand the sequence
                while (st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};