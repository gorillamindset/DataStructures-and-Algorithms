Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 
Constraints:
1 <= s.length, t.length <= 1000
s and t consist of English letters.
==========================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION 1 ARRAY
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        // vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        vector<double> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=m;i++){
            for(int j=n;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    dp[j] = dp[j] + dp[j-1];
                }
            }
        }
        return dp[n];
}

==========================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<double> dp(n+1,0),curr(n+1,0);
        dp[0]=1,curr[0]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = dp[j-1] + dp[j] ;
                }
                else{
                    curr[j] = dp[j];
                }
            }
            dp = curr;
        }
        return (int)dp[n];
}
==========================================================================================================================================================================================================================================
TABULATION
int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[m][n];
    }
==========================================================================================================================================================================================================================================
MEMOIZATION
class Solution {
public:

    int counts(int i,int j,string s,string t,vector<vector<int>>& dp){
        if(i<0 || j<0){
            if(j<0) return 1;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans =0;
        if(s[i]==t[j]){
            ans+=counts(i-1,j-1,s,t,dp);
        }
        ans+=counts(i-1,j,s,t,dp);
        return dp[i][j] = ans; 
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return counts(s.size()-1,t.size()-1,s,t,dp);
    }
};
