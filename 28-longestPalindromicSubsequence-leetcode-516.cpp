Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.

=================================================================================================================================================================================================================================

TABULATION WITH SPACE OPTIMIZATION
class Solution {
public:
    int longestPalindromeSubseq(string A) {
        int len= A.size();
        string B;
        for(int i=len-1;i>=0;i--){
            B.push_back(A[i]);
        }
        vector<int> dp(len+1,0),curr(len+1,0);
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(A[i-1]==B[j-1]){
                    curr[j]=1+dp[j-1];
                }
                else{
                    curr[j] = max(curr[j-1],dp[j]);
                }
            }
            dp = curr;
        }
        return dp[len];
    }
};
=================================================================================================================================================================================================================================
TABULATION
class Solution {
public:
    int longestPalindromeSubseq(string A) {
        int len= A.size();
        string B;
        for(int i=len-1;i>=0;i--){
            B.push_back(A[i]);
        }
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[len][len];
    }
};
