A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13

========================================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION (1 ARRAY)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	vector<int> dp(maxWeight+1,0);
	if(weight[0]<=maxWeight) dp[weight[0]] = value[0];
	for(int i=1;i<n;i++){
		for(int target=maxWeight;target>=0;target--){
			int notTake = dp[target];
			int take = 0;
			if(weight[i]<=target) take+=value[i] + dp[target-weight[i]];
			dp[target] = max(take,notTake);
		}
	}
	int maxi = INT_MIN;
	for(int i=0;i<=maxWeight;i++){
		maxi = max(maxi,dp[i]);
	}
	return maxi;

========================================================================================================================================================================================================================

TABULATION WITH SPACE OPTIMIZATION(2 ARRAYS)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	vector<int> dp(maxWeight+1,0);
	vector<int> curr(maxWeight+1,0);
	if(weight[0]<=maxWeight) dp[weight[0]] = value[0];
	for(int i=1;i<n;i++){
		for(int target=0;target<=maxWeight;target++){
			int notTake = dp[target];
			int take = 0;
			if(weight[i]<=target) take+=value[i] + dp[target-weight[i]];
			curr[target] = max(take,notTake);
		}
		dp = curr;
	}
	int maxi = INT_MIN;
	for(int i=0;i<=maxWeight;i++){
		maxi = max(maxi,dp[i]);
	}
	return maxi;
)

========================================================================================================================================================================================================================

MEMOIZATION

int maximize(int index,vector<int>&weight,vector<int>&value,int target,vector<vector<int>>&dp){
	if(index==0){
		if(weight[0]<=target) return dp[index][target] = value[index];
		return dp[index][target] = 0;
	}
	if(dp[index][target]!=-1) return dp[index][target];
	int notTake = maximize(index-1,weight,value,target,dp);
	int take = 0;
	if(weight[index]<=target) take += value[index] + maximize(index-1,weight,value,target-weight[index],dp);
	return dp[index][target] =  max(take,notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(weight.size(),vector<int>(maxWeight+1,-1));
	return maximize(weight.size()-1,weight,value,maxWeight,dp);
}
