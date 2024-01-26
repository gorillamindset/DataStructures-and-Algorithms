Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
  
==========================================================================================================================================================================================================================================================
MEMOIZATION SOLUTION
  
class Solution {
public:
    int PathSum(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(m==0 && n==0) return dp[0][0]=grid[0][0];
        if(m<0 || n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=grid[m][n]+min(PathSum(m-1,n,grid,dp),PathSum(m,n-1,grid,dp));
    }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return PathSum(m-1,n-1,grid,dp);
    }
};
==========================================================================================================================================================================================================================================================
 TABULATION WITH SPACE OPTIMIZATION   
 
 int minPathSum(vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        dp[0]=grid[0][0];
        for(int i=1;i<n;i++) dp[i]=grid[0][i]+dp[i-1];
        for(int i=1;i<m;i++){
            int prev = INT_MAX;
            for(int j=0;j<n;j++){
                if(j==0){ 
                    dp[j]=dp[j]+grid[i][j];
                    prev = dp[j];
                }
                else{
                    dp[j]=min(dp[j],prev)+grid[i][j];
                    prev = dp[j];
                }
            }
        }
        return dp.back();
    }
