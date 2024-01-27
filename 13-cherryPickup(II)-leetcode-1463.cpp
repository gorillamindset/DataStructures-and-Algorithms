You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:
From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 
Example 1:
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

Example 2:
Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
 

Constraints:
rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100

======================================================================================================================================================================================================================================================
MEMOIZATION

class Solution {
public:
    int cherry(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(i>grid.size()-1 ||j1>grid[0].size()-1 || j2>grid[0].size()-1 ||j1<0 || j2<0 ){
            return INT_MIN;
        }
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi = INT_MIN;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                maxi = max(cherry(i+1,j1+a,j2+b,grid,dp),maxi);
            }
        }
        if(j1==j2) return dp[i][j1][j2]=maxi+grid[i][j1];
        return dp[i][j1][j2]= maxi+grid[i][j1]+grid[i][j2];
    }



    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), 
        vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(),-1)));
        return cherry(0,0,grid[0].size()-1,grid,dp);
    }
};
======================================================================================================================================================================================================================================================
TABULATION 

    int cherryPickup(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(n,0)));

        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1]+grid[m-1][j2]; 
            }
        }

        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi =INT_MIN;
                    for(int a=-1;a<=1;a++){
                        for(int b=-1;b<=1;b++){
                            int value=0;
                            if(j1==j2) value+=grid[i][j1];
                            else value+=grid[i][j1]+grid[i][j2];
                            if(j1+a>=0 && j2+b>=0 && j1+a<n && j2+b<n){
                                value+=dp[i+1][j1+a][j2+b];
                                maxi = max(maxi,value);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;  
                } 
            }
        }
        return dp[0][0][n-1];
    }

======================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION
 
 int cherryPickup(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2) dp[j1][j2] = grid[m-1][j1];
                else dp[j1][j2] = grid[m-1][j1]+grid[m-1][j2]; 
            }
        }
        vector<vector<int>> curr(n,vector<int>(n,0));
        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi =INT_MIN;
                    for(int a=-1;a<=1;a++){
                        for(int b=-1;b<=1;b++){
                            int value=0;
                            if(j1==j2) value+=grid[i][j1];
                            else value+=grid[i][j1]+grid[i][j2];
                            if(j1+a>=0 && j2+b>=0 && j1+a<n && j2+b<n){
                                value+=dp[j1+a][j2+b];
                                maxi = max(maxi,value);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;  
                } 
            }
            dp=curr;
        }
        return dp[0][n-1];

======================================================================================================================================================================================================================================================


