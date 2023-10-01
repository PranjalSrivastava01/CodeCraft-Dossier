#include <bits/stdc++.h> 
int fun(int ind,vector<int> &nums,vector<int> &dp)
{
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int fs=nums[ind]+fun(ind-2,nums,dp);
    int ss=0+fun(ind-1,nums,dp);
    return dp[ind]= max(fs,ss);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int ind=nums.size()-1;
 vector<int>dp(ind+1,-1);
   return fun(ind,nums,dp);
}