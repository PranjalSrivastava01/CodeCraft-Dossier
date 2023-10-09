int Prnjl(int i,int currodlen,vector<int>&price,vector<vector<int>>&dp)
{
	if(i==0) return currodlen*price[0];
	int ntake=Prnjl(i-1,currodlen,price,dp);
	int rodlen=i+1;
	int take=0;
	if(rodlen<=currodlen)
	{
		take=price[i]+Prnjl(i,currodlen-rodlen,price,dp);
	}
	return max(take,ntake);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=i*price[0];
	}
	for(int i=1;i<n;i++)
	{
		for(int currodlen=0;currodlen<=n;currodlen++)
		{
				int ntake=dp[i-1][currodlen];
	            int rodlen=i+1;
	            int take=0;
	           if(rodlen<=currodlen)
	{
		take=price[i]+dp[i][currodlen-rodlen];
	}
	dp[i][currodlen]=max(take,ntake);
		}
	}
	return dp[n-1][n];
}
