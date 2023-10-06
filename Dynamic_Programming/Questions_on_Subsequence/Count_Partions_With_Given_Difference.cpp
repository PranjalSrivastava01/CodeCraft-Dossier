#include <bits/stdc++.h> 
int mod = 1000000007;
int Prnjl(int i,int sum,vector<int>&arr,vector<vector<int>>&dp)
{
    if(i==0)
    {
        if(sum==0 && arr[0]==0) return 2;
        if(sum==0 || arr[0]==sum) return 1;
        return 0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int npic=Prnjl(i-1,sum,arr,dp);
    int pic=0;
    if(arr[i]<=sum) pic=Prnjl(i-1,sum-arr[i],arr,dp);
    return dp[i][sum]=(pic+npic)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int s=accumulate(arr.begin(),arr.end(),0);
    if(s-d<0 || (s-d)%2) return 0;
    s=(s-d)/2;
    vector<vector<int>>dp(n,vector<int>(s+1,-1));
    return Prnjl(n-1,s,arr,dp)%mod;
}


