You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
  
Example 2:
Input: nums = [1], target = 1
Output: 1
 

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000


================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION
  
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum-target)%2 || sum-target<0) return 0;
        int newT = (sum-target)/2;
        vector<int> dp(newT+1,0);
        vector<int> curr(newT+1,0);

        if(nums[0]==0) dp[0]=2;
        else dp[0]=1;

        if(nums[0]<=newT && nums[0]!=0) dp[nums[0]]=1;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=newT;j++){ 
                int notTake = dp[j];
                int take = 0;
                if(nums[i]<=j) take+=dp[j-nums[i]];
                curr[j] = take+notTake;
            }
            dp = curr;
        }
        return dp[newT];
    }
