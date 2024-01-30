Problem statement
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.
Example:
Input: 'arr' = [1, 1, 4, 5]
Output: 3
Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4 5
1 4 4 5
Sample Output 1 :
 3
Explanation For Sample Output 1:
The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.
Sample Input 2 :
3 2
1 1 1
Sample Output 2 :
3
Explanation For Sample Output 1:
There are three 1 present in the array. Answer is the number of ways to choose any two of them.
Sample Input 3 :
3 40
2 34 5
Sample Output 3 :
0
Expected time complexity :
The expected time complexity is O('n' * 'k').
Constraints:
1 <= 'n' <= 100
0 <= 'arr[i]' <= 1000
1 <= 'k' <= 1000

Time limit: 1 sec

================================================================================================================================================================================================
TABULATION
  
int findWays(vector<int>& arr, int k)
{
	vector<vector<int>> dp(arr.size(),vector<int>(k+1,0));
	if(arr[0]<=k && arr[0]!=0) dp[0][arr[0]]=1;
	if(arr[0]==0) dp[0][0]=2;
	else dp[0][0]=1;
	vector<vector<int>> curr(arr.size(),vector<int>(k+1,0));
	for(int i=0;i<arr.size();i++){
		dp[i][0] = 1;
		curr[i][0] = 1;
	}
	for(int i=1;i<arr.size();i++){
		for(int j=0;j<=k;j++){
			int notTake = dp[i-1][j];
			int take = 0;
			if(arr[i]<=j) take+=dp[i-1][j-arr[i]];
			curr[i][j] = (take+notTake)%1000000007;
		}
		dp = curr;
	}
	return dp[arr.size()-1][k];
}
================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION
  
int findWays(vector<int>& arr, int k)
{
	vector<int> dp(k+1,0);
	if(arr[0]<=k && arr[0]!=0) dp[arr[0]]=1;
	vector<int> curr(k+1,0);
	curr[0]=1;
	if(arr[0]==0) dp[0]=2;
	else dp[0]=1;
	for(int i=1;i<arr.size();i++){
		for(int j=0;j<=k;j++){
			int notTake = dp[j];
			int take = 0;
			if(arr[i]<=j) take+=dp[j-arr[i]];
			curr[j] = (take+notTake)%1000000007;
		}
		dp = curr;
	}
	return dp[k];
}
================================================================================================================================================================================================

MEMOIZATION
  
int subset(int index,vector<int>&arr,int target,vector<vector<int>>&dp){
	if(index<0) return 0;
	if(target==0) return dp[index][target] = 1;
	if(index==0){
		if(target ==0 && arr[0]==0) return  2;
		if(target ==0 || target==arr[0]) return 1;;
		return dp[0][target]=0;
	}
	if(dp[index][target]!=-1) return dp[index][target];
	int notTake = subset(index-1,arr,target,dp);
	int take = 0;
	if(arr[index]<=target) take = subset(index-1,arr,target-arr[index],dp);
	return dp[index][target] = (take%1000000007)+(notTake%1000000007);
}


int findWays(vector<int>& arr, int k)
{
	vector<vector<int>> dp(arr.size(),vector<int>(k+1,-1));
	return (subset(arr.size()-1,arr,k,dp))%1000000007;
}
