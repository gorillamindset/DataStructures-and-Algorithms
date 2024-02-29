Given a string s, partition s such that everysubstringof the partition is apalindrome
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1

Constraints:
    1 <= s.length <= 2000
    s consists of lowercase English letters only.

===============================================================================================================================================================================================
TABULATION
int isPalindrome(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }


    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int mini = INT_MAX;
                for(int j=i;j<n;j++){
                    if(isPalindrome(i,j,s)){
                        mini = min(mini,1+dp[j+1]);
                    }
                }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
===============================================================================================================================================================================================
MEMOIZATION BUT WITH NORMAL PARTITIONS
    bool isPalindrome(int i,int j,string&s,vector<vector<int>>&dp2){
        if(dp2[i][j]!=-1) return dp2[i][j];
        while(i<j){
            if(s[i]!=s[j]) return dp2[i][j] = 0;
            i++;
            j--;
        }
        return dp2[i][j] = 1;
    }


    int cuts(int i,int j,string& s,vector<vector<int>> &dp,vector<vector<int>>& dp2){
        if(i >= j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome(i,j,s,dp2)) return dp[i][j] = 0;
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
            mini = min({ 1+cuts(i,k,s,dp,dp2)+cuts(k+1,j,s,dp,dp2), mini});
        }
        return dp[i][j] = mini;
    }

      int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1)),dp2(n,vector<int>(n,-1));
        return cuts(0,s.size()-1,s,dp,dp2);
    }
===============================================================================================================================================================================================
MEMOIZATION(OPTIMIZED)----- PREFERRED

    bool isPalindrome(string& s){
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]) return 0;
        }
        return 1;
    }

    int cuts(int i,string&s,vector<int>& dp,int n){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        string temp = "";
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost = 1 + cuts(j+1,s,dp,n);
                mini = min({mini,cost});
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return cuts(0,s,dp,n)-1;
    }
===============================================================================================================================================================================================

