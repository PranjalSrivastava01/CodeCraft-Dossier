class Solution {
public:
int fun(int ind,vector<int>& nums,vector<int> &dp)
{
    if(ind<0) return 0;
    if(ind==0) return nums[0];
    if(dp[ind]!=-1) return dp[ind];
    int pic=nums[ind]+fun(ind-2,nums,dp);
    int notpic=fun(ind-1,nums,dp);
    return dp[ind]=max(pic,notpic);
}
    int rob(vector<int>& nums) {
        vector<int>temp2,temp1;
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp2(n,-1);
        vector<int>dp1(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
            temp1.push_back(nums[i]);
            } 
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int k1=fun(n-2,temp1,dp1);
        int k2=fun(n-2,temp2,dp2);
        return max(k1,k2);
        
    }
};