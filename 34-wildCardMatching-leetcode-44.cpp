Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
  
Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
  
Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 
Constraints:
0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

==============================================================================================================================================================================================================================================
          MEMOIZATION
  
class Solution {
public:

    bool match(int ind1,int ind2,string& s,string& p,vector<vector<int>> &dp){
        if(ind1<0 && ind2<0) return true;
        if(ind1>=0 && ind2<0) return false;
        if(ind2>=0 && ind1<0){
            for(int i=0;i<=ind2;i++) if(p[i]!='*') return false;
            return true;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1]==p[ind2]){
            return dp[ind1][ind2] = match(ind1-1,ind2-1,s,p,dp);
        }
        else if(p[ind2]=='*'){
            bool first = match(ind1-1,ind2,s,p,dp);
            bool second = match(ind1,ind2-1,s,p,dp);
            return dp[ind1][ind2] = first || second;
        }
        else if(p[ind2]=='?'){
            return dp[ind1][ind2] = match(ind1-1,ind2-1,s,p,dp);
        }
        return dp[ind1][ind2] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = k.size();
        if(p==s) return true;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return match(m-1,n-1,s,p,dp);
    }
};
==============================================================================================================================================================================================================================================
TABULATION

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(p==s) return true;

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int j=1;j<=n;j++){
            int flag = 1;
            for(int i=1;i<=j;i++){
                if(p[i-1]!='*'){
                    flag = 0;
                    break;
                }
            }
            dp[0][j]=flag;
        }  
        dp[0][0] = 1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j] = 0;
            }
        }
        return dp[m][n];
    }
==============================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION 2 ARRAYS
  
      bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(p==s) return true;

        vector<int> dp(n+1,0),curr(n+1,0);
        for(int j=1;j<=n;j++){
            int flag = 1;
            for(int i=1;i<=j;i++){
                if(p[i-1]!='*'){
                    flag = 0;
                    break;
                }
            }
            dp[j]=flag;
        }  
        dp[0] = 1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j] = dp[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j] = dp[j] | curr[j-1];
                }
                else curr[j] = 0;
            }
            dp = curr;
        }
        return dp[n];
    }
==============================================================================================================================================================================================================================================
