Problem statement
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.


A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.



For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.



You are given an array 'arr' consisting of 'n' positive integers.



Find the length of the longest bitonic subsequence of 'arr'.



Example :
Input: 'arr' = [1, 2, 1, 2, 1]

Output: 3

Explanation: The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.
Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1 :
5 
1 2 1 2 1
Sample Output 1:
3
Explanation For Sample Input 1:
The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.

Sample Input 2 :
5
1 2 1 3 4
Sample Output 2 :
4
Explanation For Sample Input 2:
The longest bitonic sequence for this array will be [1, 2, 3, 4].

Expected time complexity :
The expected time complexity is O(n ^ 2).

Constraints:
1 <= 'n' <= 10^3
1 <= 'arr[i]' <= 10^5

Time Limit: 1sec
===================================================================================================================================================================================================================================================
  CONSTRUCTIVE ALGO
  int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp1(n,1);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				dp1[i] = max(dp1[i],1+dp1[j]);
			}
		}
	}
	vector<int> dp2(n,1);
	for(int i =n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j]){
				dp2[i] = max(dp2[i],1+dp2[j]);
			}
		}
	}	
	int maxi = 1;
	for(int i=0;i<n;i++){
		maxi = max(dp1[i]+dp2[i]-1,maxi);
	}
	return maxi;
}
===================================================================================================================================================================================================================================================
MEMOIZATION
int lbs(int i,int j,int inc,vector<int>&arr,vector<vector<vector<int>>>&dp){
	if(i==arr.size()){
		return 0;
	}
	if(dp[i+1][j+1][inc]!=-1) return dp[i+1][j+1][inc];
	if(j==-1 || inc){
		if(arr[i]>arr[j]){
			return dp[i+1][j+1][inc] = max({1+lbs(i+1,i,inc,arr,dp),1+lbs(i+1,i,!inc,arr,dp),lbs(i+1,j,inc,arr,dp),lbs(i+1,j,!inc,arr,dp)});
		}
		else{
			return dp[i+1][j+1][inc] = max(lbs(i+1,j,!inc,arr,dp),lbs(i+1,j,inc,arr,dp));
		}
	}
	else{
		if(arr[i]<arr[j]){
			return dp[i+1][j+1][inc] =  max({1+lbs(i+1,i,inc,arr,dp),lbs(i+1,j,inc,arr,dp)});
		}
		else{
			return dp[i+1][j+1][inc] =  lbs(i+1,j,inc,arr,dp);
		}
	}
}

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
	return lbs(0,-1,1,arr,dp);
}
