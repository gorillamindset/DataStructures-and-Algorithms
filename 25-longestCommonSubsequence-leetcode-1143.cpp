Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION

    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> dp(n+1,0),curr(n+1,0);

        dp[0]=0;

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+dp[j-1];
                    continue;
                }
                else curr[j] = max(dp[j],curr[j-1]);
            }
            dp = curr;
        }
        return dp[n];

 
================================================================================================================================================================================================================================================
MEMOIZATION
 
class Solution {
public:

    int longest(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = 1 + longest(ind1-1,ind2-1,s,t,dp);
        }

        int first = longest(ind1,ind2-1,s,t,dp);
        int second = longest(ind1-1,ind2,s,t,dp);
        return dp[ind1][ind2] = max(first,second);
    }



    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return longest(s.size()-1,t.size()-1,s,t,dp);
    }
};
================================================================================================================================================================================================================================================
TABULATION
 
   int longestCommonSubsequence(string s, string t) {

       vector<vector<int>> dp(s.size(),vector<int>(t.size(),0));
       if(s[0]==t[0]) dp[0][0]=1;
       for(int i=1;i<t.size();i++){
           if(s[0]==t[i]) dp[0][i]=1;
           else dp[0][i]=dp[0][i-1];
       }
       for(int i=1;i<s.size();i++){
           if(t[0]==s[i]) dp[i][0]=1;
           else dp[i][0] = dp[i-1][0];
       }
       for(int i=1;i<s.size();i++){
           for(int j=1;j<t.size();j++){
               if(s[i]==t[j]){
                   dp[i][j]=1+dp[i-1][j-1];
                   continue;
               }
               else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
           }
       }
       return dp[s.size()-1][t.size()-1];
================================================================================================================================================================================================================================================

