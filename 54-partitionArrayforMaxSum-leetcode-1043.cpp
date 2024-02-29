Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1

Constraints:
    1 <= arr.length <= 500
    0 <= arr[i] <= 109
    1 <= k <= arr.length

==============================================================================================================================================================================================
MEMOIZATION
  int partition(int i,vector<int>& arr,int k,vector<int>&dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int maxi = -1;
        int maxsum = -1;
        for(int l=i;l<k+i && l<arr.size();l++){
            maxi = max(maxi,arr[l]);
            int sum = (l-i+1)*maxi + partition(l+1,arr,k,dp);
            maxsum = max(maxsum,sum);
        }
        return dp[i] = maxsum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return partition(0,arr,k,dp);
    }
==============================================================================================================================================================================================
  TABULATION
      int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int maxi = -1;
            int maxsum = -1;
            for(int j=i;j<k+i && j<n;j++){
                maxi = max(maxi,arr[j]);
                int sum = (j-i+1)*maxi + dp[j+1];
                maxsum = max(maxsum,sum);
            }
            dp[i] = maxsum;
        }
        return dp[0];
    }
==============================================================================================================================================================================================
