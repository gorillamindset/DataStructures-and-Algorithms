You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
  
Example 2:
Input: nums = [1,5]
Output: 10
 
Constraints:
n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
================================================================================================================================================================================================================================================
MEMOIZATION
    int coins(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = 0;
        for(int k=i;k<=j;k++){
            int cost = nums[k]*nums[i-1]*nums[j+1];
            int left = coins(i,k-1,nums,dp);
            int right = coins(k+1,j,nums,dp);
            maxi = max(maxi,cost+left+right);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int m = nums.size();
        vector<int> temp={1};
        for(auto it:nums) temp.push_back(it);
        temp.push_back(1);
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return coins(1,m,temp,dp);
    }
================================================================================================================================================================================================================================================
  TABULATION
    int maxCoins(vector<int>& nums) {
        int m = nums.size();
        vector<int> temp={1};
        for(auto it:nums) temp.push_back(it);
        temp.push_back(1);       
        vector<vector<int>> dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i>j) continue;
                int maxi = 0;
                for(int k=i;k<=j;k++){
                    int cost = temp[k]*temp[i-1]*temp[j+1];
                    int left = dp[i][k-1]; 
                    int right = dp[k+1][j]; 
                    maxi = max(maxi,cost+left+right);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][m];
    }
================================================================================================================================================================================================================================================
