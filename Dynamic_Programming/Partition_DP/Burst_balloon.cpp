#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Prnjl(int i,int j,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long int maxi=-1;
        for(int ind=i;ind<=j;ind++)
        {
            long long int steps=nums[i-1]*nums[ind]*nums[j+1]+Prnjl(i,ind-1,nums,dp)+Prnjl(ind+1,j,nums,dp);
            maxi=max(maxi,steps);
        }
        return dp[i][j]=maxi;
    }
    // int maxCoins(vector<int>& nums) {
    //      int n=nums.size();
    //     nums.push_back(1);
    //     nums.insert(nums.begin(),1);
    //     vector<vector<int>>dp(n+3,vector<int>(n+3,-1));
    //     return Prnjl(1,n,nums,dp);
    // }
};