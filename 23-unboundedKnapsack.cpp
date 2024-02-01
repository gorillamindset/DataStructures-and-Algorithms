/*
Problem statement
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:
1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.
  
The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3 15
7 2 4
5 10 20

Expected Answer:
21
Output on console:
21
Explanation of Sample Input 1
The given knapsack capacity is 15. We can fill the knapsack as [1, 1, 1] giving us profit 21 and as [1,2] giving us profit 9. Thus maximum profit will be 21.
Sample Input 2
2 3
6 12
4 17

Expected Answer:
0
Output on console:
0
Explanation of Sample Input 2:
We can clearly see that no item has weight less than knapsack capacity. Therefore we can not fill knapsack with any item.

Expected Time Complexity:
Try to solve this in O(n*w).

Constraints
1 <= n <= 10^3
1 <= w <= 10^3
1 <= profit[i] , weight[i] <= 10^8
Time Limit: 1 sec
*/
================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> dp(w+1,0),curr(w+1,0);
    for(int i =0;i<=w;i++){
        if(weight[0]<=i){
            dp[i]=(i/weight[0])*profit[0];
        }
    }
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notTake = dp[j];
            int take = 0;
            if(weight[i]<=j){
                take+= profit[i]+curr[j-weight[i]];
            }
            curr[j]=max(take,notTake);
        }
        dp =curr;
    }
    return dp[w];
}
================================================================================================================================================================================================================================================
MEMOIZATION
  

int maximize(int ind,int target,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){

    if(target==0) return 0;
    if(ind==0){
        if(weight[ind]<=target){
            return (target/weight[ind])*profit[ind];
        }
        return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notTake = maximize(ind-1,target,profit,weight,dp);
    int take =0;
    if(weight[ind]<=target){
        take+=profit[ind] + maximize(ind,target-weight[ind],profit,weight,dp);
    }
    return dp[ind][target] = max(take,notTake);
}



int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return maximize(n-1,w,profit,weight,dp);
}
