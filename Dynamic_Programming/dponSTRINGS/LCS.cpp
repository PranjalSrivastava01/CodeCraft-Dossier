class Solution {
public:
int Prnjl(int i,int j,string text1, string text2,vector<vector<int>>dp)
{
if(i<0 || j<0) return 0;
if(dp[i][j]!=-1) return dp[i][j];
if(text1[i]==text2[j])
{
    return dp[i][j]=1+Prnjl(i-1,j-1,text1,text2,dp);
}
return dp[i][j]=max(Prnjl(i,j-1,text1,text2,dp),Prnjl(i-1,j,text1,text2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
            if(text1[i]==text2[j])
             {
             dp[i][j]=1+dp[i-1][j-1];
             }
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n1-1][n2-1];
    }
};
/////////////////////index shifting///////////////////////