You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
  
Example 2:
Input: prices = [1]
Output: 0
 

Constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
===================================================================================================================================================================================================================================================
  MEMOIZATION
class Solution {
public:
    int profit(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int Buy = profit(i+1,!buy,prices,dp)-prices[i];
            int notBuy = profit(i+1,buy,prices,dp);
            return dp[i][buy] = max(Buy,notBuy);
        }
        else{
            int Sell = profit(i+2,!buy,prices,dp)+prices[i];
            int notSell = profit(i+1,buy,prices,dp);
            return dp[i][buy] = max(Sell,notSell);
        }
    }


    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return profit(0,1,prices,dp);
    }
};
===================================================================================================================================================================================================================================================
