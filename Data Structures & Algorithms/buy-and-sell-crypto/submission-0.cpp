
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {

            // Maximum profit if we sell today
            int profit = prices[i] - minPrice;

            maxProfit = max(maxProfit, profit);

            // Update minimum buying price
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
