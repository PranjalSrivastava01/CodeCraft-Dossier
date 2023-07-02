#include <bits/stdc++.h> 
long long ans=0;
void merge(long long *arr, int l, int m, int r)
{
vector<int>temp;
int i=l, j=m+1, k=l, b[r+1];

 

    while(i<=m && j<=r){

        if(arr[i]<=arr[j])b[k++]=arr[i++];

        else {

            ans+= m-i+1;

            b[k++]=arr[j++];

        }

    }

    while(i<=m)b[k++]=arr[i++];

    while(j<=r)b[k++]=arr[j++];

    for(int u=l;u<=r;u++)arr[u]=b[u];

}
void ms(long long *arr, int low,int high)
{
    if(low>=high)  return;
    int mid=(low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}
long long getInversions(long long *arr, int n){
    int low=0;
    int high=n-1;
    ms(arr,low,high);
    return ans;
}