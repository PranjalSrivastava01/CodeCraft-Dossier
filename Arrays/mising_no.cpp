#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xr=0;
	for(int i=0;i<n;i++)
	{
		xr=xr^arr[i];
		xr=xr^(i+1);
	}
	int bitno;
	while(1)
	{
		if((xr&(1<<bitno))!=0) break;
		bitno++;
	}
	int zero=0,one=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]^(1<<bitno))
		{
      zero=zero^arr[i];
		}
		else
		{
			one=one^arr[i];
		}
	}
		for(int i=0;i<n;i++)
	{
		if((i+1)^(1<<bitno))
		{
          zero=zero^(i+1);
		}
		else
		{
			one=one^(i+1);
		}
	}
	return {zero,one};
}
