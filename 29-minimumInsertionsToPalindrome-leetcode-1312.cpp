Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 
Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.

=======================================================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION
class Solution {
public:
    int minInsertions(string s) {
        int len = s.size();
        string t;
        for(int i=len-1;i>=0;i--) t.push_back(s[i]);
        vector<int> dp(len+1,0),curr(len+1,0);
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = 1 + dp[j-1];
                }
                else{
                    curr[j] = max(curr[j-1],dp[j]);
                }
            }
            dp = curr;
        }
        return len-dp[len];
    }
};
=======================================================================================================================================================================================================================================================
