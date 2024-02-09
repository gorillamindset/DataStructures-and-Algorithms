Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.


Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
  
Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 
Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
=====================================================================================================================================================================================================================================================
PLAIN RECURSION 
      int LDS(int i,vector<int>&nums,vector<int>&subset,vector<int>&ans){
        if(i == nums.size()){
            if(subset.size()>ans.size()){
                ans = subset;
            }
            return 0;
        }
        int flag = true;
        for(int j=0;j<subset.size();j++){
            if(subset[j]%nums[i]!=0 && nums[i]%subset[j]!=0){
                flag = false;
            }
        }
        if(flag){
            subset.push_back(nums[i]);
            int take = LDS(i+1,nums,subset,ans);
            subset.pop_back();
            int notTake = LDS(i+1,nums,subset,ans);
            return max(take,notTake);
        }
        else{
            return LDS(i+1,nums,subset,ans);
        }
    }


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans,subset;
        LDS(0,nums,subset,ans);
        return ans;
    }
=====================================================================================================================================================================================================================================================
CONSTRUCTIVE ALGORITHM
vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> temp(nums.size());
        for(int i=0;i<n;i++){
            temp[i] = {nums[i]};
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int flag = true;
                if(nums[i]%nums[j]!=0 && nums[j]%nums[i]!=0) flag = false;
                if(flag){
                    if(temp[j].size()+1>temp[i].size()){
                        temp[i] = temp[j];
                        temp[i].push_back(nums[i]);
                    }
                }
            }
        }
        int maxi= 0;
        int ind = -1;
        for(int i=0;i<temp.size();i++){
            if(temp[i].size()>=maxi){
                maxi= temp[i].size();
                ind = i;
            }
        }
        cout<<maxi;
        return temp[ind];
    }
