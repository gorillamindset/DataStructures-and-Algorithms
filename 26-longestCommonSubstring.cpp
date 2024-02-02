Problem statement
You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.
A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.



Example:
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.
Output: 3
Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
wasdijkl
wsdjkl
Sample Output 1:
 3
Explanation Of Sample Input 1 :
 The longest common substring is “jkl”, of length 3.

Sample Input 2:
tyfg
cvbnuty
Sample Output 2:
2
Explanation Of Sample Input 2 :
The longest common substring is “ty”, of length 2.
Expected time complexity:
The expected time complexity is O(n*m),
Where ‘n’ and ‘m’ are the lengths of ‘st1’ and ‘str2’ respectively.
Constraints:
1 <= str1.length <= 1000
1 <= str2.length <= 1000

==========================================================================================================================================================================================================================================

TABULATION WITH SPACE OPTIMIZATION
 
int lcs(string &str1, string &str2){
    int m = str1.size();
    int n = str2.size();
    vector<int> dp(n+1,0),curr(n+1,0);

    int ans = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                curr[j] = 1+dp[j-1];
                ans = max(ans,curr[j]);
            }
            else curr[j] = 0;
        }
        dp = curr;
    }
    return ans;
}
==========================================================================================================================================================================================================================================
TABULATION

int lcs(string &str1, string &str2){
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    int ans = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}
