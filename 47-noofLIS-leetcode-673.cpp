Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
  
Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 
Constraints:
1 <= nums.length <= 2000
-106 <= nums[i] <= 106
===================================================================================================================================================================================================================================================
  CONSTRUCTIVE OR TABULATION SOLUTION
int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(),1),dp2(nums.size(),1);
        int maxi = 1;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]+1>dp[i] && nums[j]<nums[i]){
                    dp2[i] = dp2[j];
                    dp[i] = dp[j] + 1;    
                } 
                else if(dp[j]+1==dp[i] && nums[j]<nums[i]){
                    dp2[i] += dp2[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) count+=dp2[i];
        }
        return count;
    }
===================================================================================================================================================================================================================================================
