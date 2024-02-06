You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
  
Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
  
Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 
Constraints:
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
===========================================================================================================================================================================================================================================
  TABULATION WITH SPACE OPTIMIZATION--SPACE 0(1)

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int left= prices[n-1];
        int right = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int templeft = left;
            int tempright = right;
            left = max(tempright+prices[i],templeft);
            right = max(templeft-prices[i],tempright);
        }
        return right;
      }
===========================================================================================================================================================================================================================================
MEMOIZATION
class Solution
{
    public:
int profit(int i, int buy, vector<int> &prices, vector<vector< int>> &dp)
        {
            if (i == prices.size() - 1)
            {
                if (buy) return 0;
                return prices[i];
            }
            if (dp[i][buy] != -1) return dp[i][buy];
            if (buy == 1)
            {
                int Buy = profit(i + 1, !buy, prices, dp) - prices[i];
                int notBuy = profit(i + 1, buy, prices, dp);
                return dp[i][buy] = max(Buy, notBuy);
            }
            else
            {
                int sell = prices[i] + profit(i + 1, !buy, prices, dp);
                int notSell = profit(i + 1, buy, prices, dp);
                return dp[i][buy] = max(sell, notSell);
            }
        }

    int maxProfit(vector<int> &prices)
    {
       	int n = prices.size();
       	vector<vector < int>> dp(n, vector<int> (2, -1));
       	return profit(0, 1, prices, dp);
    }
};
===========================================================================================================================================================================================================================================
TABULATION
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector < int>> dp(n, vector<int> (2, 0));
        dp[n - 1][0] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i][0] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
        }
        return dp[0][1];
    }
===========================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION 2 ARRAYS
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2,0),curr(2,0);
        // vector<vector < int>> dp(n, vector<int> (2, 0));
        dp[0] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            curr[0] = max(prices[i] + dp[1], dp[0]);
            curr[1] = max(dp[0] - prices[i], dp[1]);
            dp = curr;
        }
        return dp[1];
    }
===========================================================================================================================================================================================================================================
