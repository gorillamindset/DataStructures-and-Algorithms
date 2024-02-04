
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
 

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
  
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
============================================================================================================================================================================================================================================================
  TABULATION WITH SPACE OPTIMIZATION
int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<int> dp(n+1,0),curr(n+1,0);
        for(int j=1;j<=n;j++){
            dp[j] = j;
        }
        for(int i=1;i<=m;i++){
            curr[0]=dp[0];
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = dp[j-1];
                }
                else{
                    curr[j] = 1 + min(min(curr[j-1],dp[j]),dp[j-1]);
                }
            }
            dp = curr;
            dp[0]++;
        }
        return dp[n];
    }
============================================================================================================================================================================================================================================================
MEMOIZATION
class Solution {
public:
    int dist(int i,int j,string& s,string& t,vector<vector<int>> &dp){
        if(i<0 || j<0){
            if(j<0) return i+1;
            return j+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = dist(i-1,j-1,s,t,dp);
        }
        int insert = 1+dist(i,j-1,s,t,dp);
        int del = 1+dist(i-1,j,s,t,dp);
        int replace = 1+dist(i-1,j-1,s,t,dp);
        return dp[i][j] = min(min(insert,del),replace);
    }

    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dist(m-1,n-1,s,t,dp);
    }
};
============================================================================================================================================================================================================================================================
  TABULATION
  int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            dp[i][0] = i;
        }
        for(int j=1;j<=n;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(1+dp[i][j-1],1+dp[i-1][j]);
                    dp[i][j] = min(dp[i][j],1+dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
