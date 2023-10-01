#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &k)
{
   int prev1=0;
   int prev2=0;
   int curr=0;
   for(int i=1;i<n;i++)
   {
       int fs=prev1+abs(k[i]-k[i-1]);
       int ss=INT_MAX;
       if(i>1)
       {
        ss=prev2+abs(k[i]-k[i-2]);
       }
       curr=min(fs,ss);
       prev2=prev1;
       prev1=curr;
   }
   return curr;
}