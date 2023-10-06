class Solution {
public:
bool Prnjl(int i,int target,vector<int>& a,vector<vector<int>>& dp)
{
if(target==0) return true;
if(i==0) return (a[0]==target);
if(dp[i][target]!=-1) return dp[i][target];
bool  npic=Prnjl(i-1,target,a,dp);
bool pic=a[i]<=target?Prnjl(i-1,target-a[i],a,dp):false;
return dp[i][target]=(pic || npic);

}
    bool canPartition(vector<int>& a) {
        int s=0;
        int n=a.size();
        s=accumulate(a.begin(), a.end(), 0);
        vector<vector<int>>dp(n,vector<int>(s,-1));
        if(s%2!=0) return false;
        return Prnjl(a.size()-1,s/2,a,dp);

    }
};