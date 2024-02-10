You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 
Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
==================================================================================================================================================================================================================================================
TABULATION || CONSTRUCTIVE ALGORITHM

    int comp(string& s,string& t){
        int i=0,j=0;
        int count = 0;
        int flag = (s.size()>t.size());
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                if(flag) i++;
                else j++;
                count++;
            } 
        }
        while(i<s.size()){
            count++;
            i++;
        } 
        while(j<t.size()){
            count++;
            j++;
        }
        if(count==1) return 1;
        return 0;
    }

    int longestStrChain(vector<string>& words) {
        vector<pair<int,int>> temp(words.size());
        for(int i=0;i<words.size();i++) temp[i] = {words[i].size(),i};
        sort(temp.begin(),temp.end());
        vector<string> realWords;
        for(auto it:temp){
            realWords.push_back(words[it.second]);
        }
        int n = words.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(comp(realWords[j],realWords[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                }
                maxi= max(maxi,dp[i]);
            }
        }
        return maxi;
    }
==================================================================================================================================================================================================================================================
MEMOIZATION
class Solution {
public:
    int comp(string& s,string& t){
        int i=0,j=0;
        int count = 0;
        int flag = (s.size()>t.size());
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                if(flag) i++;
                else j++;
                count++;
            } 
        }
        while(i<s.size()){
            count++;
            i++;
        } 
        while(j<t.size()){
            count++;
            j++;
        }
        if(count==1) return 1;
        return 0;
    }


    int LSC(int i,int j,vector<string>&words,vector<vector<int>>&dp){
        if(i==words.size()){
            return 0;
        }
        int flag = false;
        
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];

        if(j==-1) flag = true;
        else flag = comp(words[i],words[j]) || comp(words[j],words[i]);

        if(j==-1 || flag){
            return dp[i+1][j+1] = max(1+LSC(i+1,i,words,dp),LSC(i+1,j,words,dp));
        }
        else{
            return dp[i+1][j+1] = LSC(i+1,j,words,dp);
        }
    }


    int longestStrChain(vector<string>& words) {
        vector<pair<int,int>> temp(words.size());
        for(int i=0;i<words.size();i++) temp[i] = {words[i].size(),i};
        sort(temp.begin(),temp.end());
        vector<string> realWords;
        for(auto it:temp){
            realWords.push_back(words[it.second]);
        }
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return LSC(0,-1,realWords,dp);
    }
};
================================================================================================================================================================================================================================================
  
