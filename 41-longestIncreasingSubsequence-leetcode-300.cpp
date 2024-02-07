Given an integer array nums, return the length of the longest strictly increasing 
subsequence

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4
  
Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104
===================================================================================================================================================================================================================================================
MEMOIZATION
class Solution
{
    public:
        int sequence(int i, int prev, vector<int> &nums, vector<vector< int>> &dp)
        {
            if (i == nums.size())
            {
                return 0;
            }
            if (dp[i + 1][prev + 1] != -1) return dp[i + 1][prev + 1];
            if (prev == -1 || nums[prev] < nums[i])
            {
                return dp[i + 1][prev + 1] = max(1 + sequence(i + 1, i, nums, dp), sequence(i + 1, prev, nums, dp));
            }
            else
            {
                return dp[i + 1][prev + 1] = sequence(i + 1, prev, nums, dp);
            }
        }

    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector < int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, -1));
        return sequence(0, -1, nums, dp);
    }
};
===================================================================================================================================================================================================================================================
