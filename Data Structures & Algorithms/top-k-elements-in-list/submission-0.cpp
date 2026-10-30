class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        for (auto& entry : freq_map) {
            min_heap.push({entry.second, entry.first});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        // Step 3: Extract the elements from the heap
        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }
};