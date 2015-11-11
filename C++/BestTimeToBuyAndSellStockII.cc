// Say you have an array for which the ith element is the price of
// a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete
// as many transactions as you like (ie, buy one and sell one share
// of the stock multiple times). However, you may not engage in
// multiple transactions at the same time (ie, you must sell the
// stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int max_profit = 0;
        int beg = 0, end = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= prices[i - 1])
                end = i;
            else {
                max_profit += prices[end] - prices[beg];
                beg = end = i;
            }
        }
        return max_profit + prices[end] - prices[beg];
    }
};
