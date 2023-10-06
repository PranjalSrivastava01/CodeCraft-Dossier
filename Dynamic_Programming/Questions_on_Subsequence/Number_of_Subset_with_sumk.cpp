int Prnjl(int i,int target,vector<int>&arr,vector<vector<int>>&dp)
{
	if(target==0)
	{
    return 1;
	}
	if(i==0)
	{
	if(arr[0]==target)
	{
		return 1;
	}
	else
	{
		return 0;
	}
    }
	if(dp[i][target]!=-1) return dp[i][target];
	int npic=Prnjl(i-1,target,arr,dp);
	int pic=0;
	if(arr[i]<=target)
	{
		pic=Prnjl(i-1,target-arr[i],arr,dp);
	}
	return dp[i][target]=(npic+pic);

}
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
	int ans=Prnjl(n-1,k,arr,dp);
	return ans;
}
