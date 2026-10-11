class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        
        for (const auto& interval : intervals) {
            // If merged is empty OR no overlap, insert interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } 
            // If overlap exists, merge with previous interval
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
