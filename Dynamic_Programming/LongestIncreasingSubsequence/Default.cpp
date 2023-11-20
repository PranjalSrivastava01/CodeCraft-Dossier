class Solution {
public:
    int Prnjl(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(ind==nums.size()) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int ntake=Prnjl(ind+1,prev,nums,dp);
        int take=-1;
        if(prev==0 || nums[ind]>nums[prev-1])
        {
         take=1+Prnjl(ind+1,ind+1,nums,dp);
        }
        return dp[ind][prev]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return Prnjl(0,0,nums,dp);
    }
};