class Solution {
public:
int Prnjl(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
{
    if(i>j) return 0;
    int mini=1e7;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<=j;k++)
    {
     int steps=cuts[j+1]-cuts[i-1]+Prnjl(i,k-1,cuts,dp)+Prnjl(k+1,j,cuts,dp);
     mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return Prnjl(1,c,cuts,dp);
    }
};