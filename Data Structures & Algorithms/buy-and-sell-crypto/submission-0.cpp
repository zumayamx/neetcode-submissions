/**
 * ONE PASS APPROACH: 
 * The key idea is to keep in track the min price,
 * since the prices are sorted by day. So for example
 * day one, day two, day trhee, day n. 
 *
 * Since you only need to choose a single day to buy
 * and different day to sell it. 
 * 
 * You need to find that minimum price and that maximun price to sell.
 * So, we could select a day as minimun price, then check the following
 * days has a new minum price, if it has update it.
 *
 * At the same time you could compute the profit between that minimun
 * price and the current price, if that profit is greater than our
 * current profit, update it.
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int i = 0; i < n; i++)
        {
            if (prices[i] < min_price) min_price = prices[i];
            else if (prices[i] - min_price > max_profit) max_profit = prices[i] - min_price;
        }

        return max_profit;
    }
};
