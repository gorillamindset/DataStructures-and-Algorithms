Problem statement:
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.


=======================================================================================================================================================================================================
MEMOIZATION APPROACH

#include <bits/stdc++.h>

void pointsCal(int index,vector<vector<int>>& dp,vector<vector<int>>&points,int n){
    if(index<0) return;
    if(index==0){
        for(int i=0;i<3;i++){
            dp[index][i]=points[index][i];
        }
        return;
    }
    pointsCal(index-1,dp,points,n);
    for(int i=0;i<3;i++){
        int maxi = INT_MIN;
        for(int j=0;j<3;j++){
            if(j==i) continue;
            maxi= max(maxi,points[index][i]+dp[index-1][j]);
        }
        dp[index][i]=max(maxi,dp[index][i]);
        // cout<<dp[index][i]<<"for index "<<index<<" and i "<<i<<endl;
    }
    return;
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(3,-1));
    pointsCal(n-1,dp,points,n);
    int maxi = 0;
    for(int i=0;i<3;i++){
        maxi = max(dp[n-1][i],maxi);
    }
    return maxi;
}
=======================================================================================================================================================================================================
TABULATION WITH SPACE OPTIMIZATION

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(3);
    for(int i=0;i<3;i++){
        dp[i] = points[0][i];
    }

    for(int i=1;i<n;i++){
        vector<int> temp(3,-1);
        for(int j=0;j<3;j++){
            int maxi = INT_MIN;
            for(int k=0;k<3;k++){
                if(k==j) continue;
                maxi = max(points[i][j]+dp[k],maxi);
            }
            temp[j]=maxi;
        } 
        for(int i=0;i<3;i++){
            dp[i]=temp[i];
        }
    }
    int maxi = dp[0];
    for(int i=1;i<3;i++){
        maxi= max(dp[i],maxi);
    }
    return maxi;
}

=======================================================================================================================================================================================================
