#include <bits/stdc++.h> 
int Prnjl(int i,int target,vector<int>&arr,vector<vector<int>>&dp)
{
    if (i == 0) {
        if (target == 0 && arr[0] == 0)
            return 2; 
        if (target == 0 || target == arr[0])
            return 1; 
        return 0; 
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int npic=Prnjl(i-1,target,arr,dp);
    int pic=0;
    if(arr[i]<=target)
    {
        pic=Prnjl(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=pic+npic;
}
int targetSum(int n, int target, vector<int>& arr) {
    int s=accumulate(arr.begin(),arr.end(),0);
    vector<vector<int>>dp(n,vector<int>(s+1,-1));
    int ans=0;
    for(int i=0;i<=s/2;i++)
    {
        int ok=Prnjl(n-1,i,arr,dp);
        if(ok>0)
        {
        if(abs(i-(s-i))==abs(target)) ans+=ok;
        }
    }
    return ans;
}
