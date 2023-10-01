#include <bits/stdc++.h> 
int fun(int ind,vector<int> &nums)
{
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    int fs=nums[ind]+fun(ind-2,nums);
    int ss=0+fun(ind-1,nums);
    return max(fs,ss);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int ind=nums.size()-1;
   return fun(ind,nums);
}