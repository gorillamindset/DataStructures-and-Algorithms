Problem statement
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
1 2 3
4
Sample Output 1:
4
Explanation for Sample Output 1:
We can make a change for the value V = 4 in four ways.
1. (1,1,1,1), 
2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1) and (1, 2, 1)]
3. (1, 3), and 
4. (2, 2)
Sample Input 2 :
3
5 3 2
1
Sample Output 2:
0


==============================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION
  
long countWaysToMakeChange(int *denominations, int n, int value)
{

    vector<long> dp(value+1,0),curr(value+1,0);
    for(int i=1;i<=value;i++){
        if(denominations[0]<=i){
            if(i%denominations[0]) continue;
            else dp[i]=1;
        }
    }
    dp[0]=1;
    // curr[0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=value;j++){
            long notTake = dp[j];
            long take = 0;
            if(denominations[i]<=j){
                take=curr[j-denominations[i]];
            }
            curr[j]=notTake+take;
            // cout<<"curr["<<j<<"]"<<curr[j]<<endl;
        }
        dp = curr;
    }
    return dp[value];
}


==============================================================================================================================================================================================================================================
MEMOIZATION
  
#include<vector>

long ways(int *denominations,int n,int value,vector<vector<long>>&dp){
    if(value==0) return 1L;
    if(n==0){
        if(denominations[n]<=value){
            if(value%denominations[n]) return 0L;
            return 1L;
        }
        return 0L;
    }
    if(dp[n][value]!=-1) return dp[n][value];
    long notTake = ways(denominations,n-1,value,dp);
    long take = 0L;
    if(denominations[n]<=value){
        take+=ways(denominations,n,value-denominations[n],dp);
    }
    return dp[n][value]=notTake+take;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
    // vector<vector<long>>dp(n,vector<long>(value+1,-1));
    // return ways(denominations,n-1,value,dp);
}
