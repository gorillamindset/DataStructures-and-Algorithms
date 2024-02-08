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
USING BINARY SEARCH
    int bs(vector<int>& temp,int toadd){
        int left= 0;
        int right = temp.size()-1;
        if(temp[right]<toadd) return -1;
        int ans = (left+right)/2;
        while(left<=right){
            int mid = (left+right)/2;
            if(temp[mid]<toadd){
                left = mid+1;
            }
            else{
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int len = 1;
        for(int i=1;i<nums.size();i++){
            int ind = bs(ans,nums[i]);
            if(ind==-1){
                ans.push_back(nums[i]);
                len++;
            } 
            else ans[ind] = nums[i];
        }
        for(auto it:ans) cout<<it<<" ";
        return len;
    }
===================================================================================================================================================================================================================================================
CONSTRUCTIVE SOLUTION
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
  //for printing the LIS this prints it in reverse order
        int ans = maxi;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==ans){
                ans--;
                cout<<nums[i]<<" ";
            }
        }
        return maxi;
    }
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
TABULATION
      int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>=-1;j--){
                if(j==-1 || nums[j]<nums[i]){
                    dp[i+1][j+1] = max(1+dp[i+2][i+1],dp[i+2][j+1]);
                }
                else{
                    dp[i+1][j+1] = dp[i+2][j+1];
                }
            }
        }
        return dp[1][0];
  }
===================================================================================================================================================================================================================================================
