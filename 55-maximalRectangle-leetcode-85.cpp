Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area. 

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
  
Example 2:
Input: matrix = [["0"]]
Output: 0
  
Example 3:
Input: matrix = [["1"]]
Output: 1
 
Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
=================================================================================================================================================================================================================================
  CONSTRUCTIVE SOLUTION USING STACKS BUT SINCE WE ARE REUSING THE LAST ROW WE CALL IT DP
  
    int maxArea(vector<int>& nums,int n,stack<int>&st){
        int maxarea=-1;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()]>=nums[i])){
                int j = st.top();
                st.pop();
                int width = i;
                if(!st.empty()) width = i - st.top() - 1;
                maxarea = max(maxarea,width*nums[j]);
            }
            st.push(i);
        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> nums(n,0);
        stack<int>st;
        int maxarea = -1;
        for(int i=0;i<m;i++){
            while(!st.empty()) st.pop();
            for(int j=0;j<n;j++){
                if(matrix[i][j]!='0') nums[j]+=(matrix[i][j]-'0');
                else nums[j] = 0;
            }
            maxarea = max(maxarea,maxArea(nums,n,st));
        }
        return maxarea;
=================================================================================================================================================================================================================================
