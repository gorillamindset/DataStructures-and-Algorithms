Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
  
Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.

================================================================================================================================================================================================================================================
TABULATION
#include<bits/stdc++.h>

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans = "";
        int i=len1,j=len2;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans+=s[i-1];
                i--,j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s[i-1];
                i--;
            }
            else{
                ans+=t[j-1];
                j--;
            }
        }
        while(i>0){
            ans.push_back(s[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(t[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
  
================================================================================================================================================================================================================================================
TABULATION

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int index = dp[len1][len2]-1;
        vector<char> ans(dp[len1][len2]);
        string temp;
        int i=s.size(),j= t.size();
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans[index] = s[i-1];
                i--,j--;
                index--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        for(int i=0;i<ans.size();i++) temp.push_back(ans[i]);
        string rans;
        i=0;
        j=0;
        int k=0;
        while(i<len1 || j<len2){
            if(s[i]==temp[k] && t[j]==temp[k]){
                rans.push_back(s[i]);
                i++,j++,k++;
            }
            else if(s[i]==temp[k]){
                while(t[j]!=temp[k]){
                    rans.push_back(t[j]);
                    j++;
                }
            }
            else if(t[j]==temp[k]){
                while(s[i]!=temp[k]){
                    rans.push_back(s[i]);
                    i++;
                }
            }
            else{
                while(s[i]!=temp[k] && t[j]!=temp[k]){
                    rans.push_back(s[i]);
                    rans.push_back(t[j]);
                    i++,j++;
                }
            }
        }
        while(i<len1){
            rans.push_back(s[i]);
            i++;
        }
        while(j<len2){
            rans.push_back(t[j]);
        }
        return rans;
    }
};
================================================================================================================================================================================================================================================
