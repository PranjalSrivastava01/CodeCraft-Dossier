class Solution {
public:
   int Prnjl(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
    if(i<0 ||j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j])
    {
        ans= 1+Prnjl(i-1,j-1,s1,s2,dp);
    }
    else 
    {
        ans=max(Prnjl(i,j-1,s1,s2,dp),Prnjl(i-1,j,s1,s2,dp));
    }
    return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int a=m-Prnjl(n-1,m-1,word1,word2,dp);
        int b=n+a-m;
        return a+b;
    }
};