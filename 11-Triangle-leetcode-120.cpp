Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row. 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
 

Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

======================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle.back().size();
        for(int i=1;i<m;i++){
            for(int j=0;j<triangle[i].size();j++){
                int temp = triangle[i][j];
                int mini = INT_MAX;
                if(j-1>=0) mini=min(triangle[i-1][j-1],mini);
                if(j<triangle[i-1].size()) mini = min(triangle[i-1][j],mini);
                triangle[i][j] += mini;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(triangle[m-1][i],ans);
        }
        return ans;

    }
};


======================================================================================================================================================================================================================================================
MEMOIZATION

class Solution {
public:
    int minSum(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(j > triangle[i].size()-1) return INT_MAX;
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return dp[i][j]=triangle[0][0];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int mini = INT_MAX;
        int left = minSum(i-1,j-1,triangle,dp);
        if(left!=INT_MAX) mini = min(mini,left);
        int right = minSum(i-1,j,triangle,dp);
        if(right!=INT_MAX) mini = min(mini,right);
        if(mini==INT_MAX) return dp[i][j]=INT_MAX;
        return dp[i][j]=mini+triangle[i][j];
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int mini = INT_MAX;
        int m = triangle.size();
        int n = triangle.back().size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            mini = min(minSum(m-1,i,triangle,dp),mini);
        }
        for(int i=0;i<n;i++){
            if(dp[m-1][i]!=INT_MAX) mini = min(dp[m-1][i],mini);
            cout<<dp[m-1][i]<<": cout"<<endl;
        }
        return mini;
    }
};
