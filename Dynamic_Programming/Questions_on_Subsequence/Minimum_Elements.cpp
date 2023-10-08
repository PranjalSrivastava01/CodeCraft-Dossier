#include <bits/stdc++.h> 
int Prnjl(int i,int target,vector<int>&a,vector<vector<int>>&dp)
{
    if(i==0)
    {
        if(target%a[0]==0) return target/a[0];
        else return 1e9;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int npic=Prnjl(i-1,target,a,dp);
    int pic=1e9;
    if(a[i]<=target)
    {
        pic=1+Prnjl(i,target-a[i],a,dp);
    }
    return dp[i][target]=min(pic,npic);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans=Prnjl(n-1,x,num,dp);
    if(ans>=1e9) return -1;
    return ans;
}