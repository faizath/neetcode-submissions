class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int max_profit = 0;
        int l = 0, r = 1;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) max_profit = max(max_profit, prices[r++] - prices[l]);
            else l = r++;
        }
        return max_profit;
    }
};
