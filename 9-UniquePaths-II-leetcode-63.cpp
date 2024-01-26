You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
Constraints:
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

======================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        if(obstacleGrid[0][0]==1) dp[0]=0;
        else dp[0]=1;
        for(int i=1;i<n;i++){
            if(dp[i-1]==0 || obstacleGrid[0][i]==1){
                dp[i]=0;
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        for(int i=1;i<m;i++){
            int prev = 0;
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[j]=0;
                    prev = 0;
                }
                else{
                    dp[j]= prev+dp[j];
                    prev = dp[j];
                }
            }
        }
        return dp.back();
    }
};

======================================================================================================================================================================================================================================================
