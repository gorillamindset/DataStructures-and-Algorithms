You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
  
Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 
Constraints:
1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
====================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION 1D ARRAY
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxi = 2*k;
        vector<int> dp(maxi+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<maxi;j++){
                if(j%2==0){
                    int Buy = dp[j+1]-prices[i];
                    int notBuy= dp[j];
                    dp[j] = max(Buy,notBuy);
                }
                else{
                    int sell = dp[j+1] + prices[i];
                    int notSell = dp[j];
                    dp[j] = max(sell,notSell);
                }
            }
        }
        int ans =0;
        for(int i=0;i<dp.size();i++){
            if(!i%2) ans = max(dp[i],ans);
        }
        return ans;
====================================================================================================================================================================================================================================================
  MEMOIZATION
class Solution {
public:
    int profit(int i,int k,vector<int>&prices,vector<vector<int>>&dp,int& maxi){
        if(i==prices.size() || k>=maxi) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k%2 == 0){
            int Buy = profit(i+1,k+1,prices,dp,maxi)-prices[i];
            int notBuy= profit(i+1,k,prices,dp,maxi);
            return dp[i][k] = max(Buy,notBuy);
        }
        else{
            int sell =profit(i+1,k+1,prices,dp,maxi) + prices[i];
            int notSell =profit(i+1,k,prices,dp,maxi);
            return dp[i][k] = max(sell,notSell);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxi = 2*k;
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return profit(0,0,prices,dp,maxi);
    }
};
====================================================================================================================================================================================================================================================
TABULATION
      int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxi = 2*k;
        vector<vector<int>> dp(n+1,vector<int>(maxi+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<maxi;j++){
                if(j%2==0){
                    int Buy = dp[i+1][j+1]-prices[i];
                    int notBuy= dp[i+1][j];
                    dp[i][j] = max(Buy,notBuy);
                }
                else{
                    int sell = dp[i+1][j+1] + prices[i];
                    int notSell = dp[i+1][j];
                    dp[i][j] = max(sell,notSell);
                }
            }
        }
        int ans =0;
        for(int i=0;i<dp[0].size();i++){
            if(!i%2) ans = max(dp[0][i],ans);
        }
        return ans;
      }
====================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION 2 ARRAYS
      int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxi = 2*k;
        vector<int> dp(maxi+1,0),curr(maxi+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<maxi;j++){
                if(j%2==0){
                    int Buy = dp[j+1]-prices[i];
                    int notBuy= dp[j];
                    curr[j] = max(Buy,notBuy);
                }
                else{
                    int sell = dp[j+1] + prices[i];
                    int notSell = dp[j];
                    curr[j] = max(sell,notSell);
                }
            }
            dp = curr;
        }
        int ans =0;
        for(int i=0;i<dp.size();i++){
            if(!i%2) ans = max(dp[i],ans);
        }
        return ans;
    }
====================================================================================================================================================================================================================================================
