You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.


Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
  
Example 2:
Input: coins = [2], amount = 3
Output: -1
  
Example 3:
Input: coins = [1], amount = 0
Output: 0
 
Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

=========================================================================================================================================================================================================================================================

TABULATION WITH SPACE OPTIMIZATION
    int coinChange(vector<int>& coins, int amount) {
      if(amount==0) return 0;
      vector<int> dp(amount+1,0);
      for(int i=1;i<=amount;i++){
          int temp = i%coins[0];
          if(temp) dp[i] = INT_MAX;
          else dp[i]=i/coins[0];
      }
      vector<int> curr(amount+1,0);
      for(int i=1;i<coins.size();i++){
          for(int j=1;j<=amount;j++){
              int notTake = dp[j];
              int take = INT_MAX;
              if(coins[i]<=j){
                  int count = j/coins[i] ;
                  if(j%coins[i]){
                      int temp = dp[j%coins[i]];
                      if(temp!=INT_MAX) count+=temp;
                      else count=INT_MAX;
                  }
                  int k = 1;
                  while(j-k*coins[i]>0){
                      if(dp[j-k*coins[i]]!=INT_MAX) count = min(k+dp[j-k*coins[i]],count);
                      k++;
                  }
                  take = count;
              }
              curr[j] = min(take,notTake); 
          }
          dp = curr;
      }
      int ans = dp[amount];
      if(ans!=INT_MAX) return ans;
      return -1;

// here you dont need to loop through the previous array every time because j-k*coins[i] is already calculated in the present array in the previous iterations. Hence better approach is below 

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1,0);
        for(int i=1;i<=amount;i++){
            int temp = i%coins[0];
            if(temp) dp[i] = INT_MAX;
            else dp[i]=i/coins[0];
        }
        vector<int> curr(amount+1,0);
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int notTake = dp[j];
                int take = INT_MAX;
                if(coins[i]<=j){
                    take = curr[j-coins[i]];
                    if(take!=INT_MAX) take++; 
                }
                curr[j] = min(take,notTake); 
            }
            dp = curr;
        }
        int ans = dp[amount];
        if(ans!=INT_MAX) return ans;
        return -1;


=========================================================================================================================================================================================================================================================
MEMOIZATION
    int coinsSum(int index,vector<int>&coins,int amount,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(index==0){
            if(coins[index]<=amount){
                int ans = coinsSum(index,coins,amount-coins[index],dp);
                if(ans!=INT_MAX) return dp[index][amount] = ans+1;
            }
            return dp[index][amount] = INT_MAX; 
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake = coinsSum(index-1,coins,amount,dp);
        int take = INT_MAX;
        if(coins[index]<=amount){
            take = coinsSum(index,coins,amount-coins[index],dp);
            if(take!=INT_MAX) take++;
        } 
        return dp[index][amount] = min(take,notTake);
    }


    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = coinsSum(coins.size()-1,coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
=========================================================================================================================================================================================================================================================
