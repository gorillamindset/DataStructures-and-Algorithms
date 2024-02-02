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
TABULATION

int lcs(string &str1, string &str2){
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    if(str1[0]==str2[0]) dp[0][0] = 1;
    for(int j=1;j<n;j++){
        if(str1[0]==str2[j]) dp[0][j]=1;
        else dp[0][j]=dp[0][j-1];
    }
    for(int i=1;i<m;i++){
        if(str2[0]==str1[i]) dp[i][0]=1;
        else dp[i][0]=dp[i-1][0];      
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(str1[i]==str2[j] ){
                if(str1[i-1]==str2[j-1]){
                  //if both the characters at that index are same and previous characters are also same the add 1+ previous substring length;
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                  //if both the characters at that index are same but previous character is not same then take this character length 1;
                else dp[i][j] = 1;
            }
            else{
              //if both characters are not same then take whatever previous substring length;
// NOTE: you can also take 0 when both characters are not same and 1 when both are same but the previous character is not same and 1+previous substring length when both characters are same and previous character is also matches;
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int maxi = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            maxi = max(maxi,dp[i][j]);
        }
    }
    return maxi;
}
