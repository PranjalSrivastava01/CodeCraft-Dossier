class Solution {
public:
const int prime = 1e9 + 7;
    int Prnjl(int i,int j,string &s , string &t,vector<vector<int>>&dp)
    {
     if(j==0) return 1;
     if(i==0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i-1]==t[j-1])
     {
         dp[i][j]=Prnjl(i-1,j-1,s,t,dp)+Prnjl(i-1,j,s,t,dp);
     }
     else
     {
       dp[i][j]=Prnjl(i-1,j,s,t,dp);
     }
        return dp[i][j];
     
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
             if(s[i-1]==t[j-1])
                {
                  dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%prime;
        }
          else
              {
                dp[i][j]=dp[i-1][j];
              }
            }
        }
        return dp[n][m];
    }
};