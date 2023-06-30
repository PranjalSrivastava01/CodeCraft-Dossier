class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
     int n=arr.size();
     int p=0;
     if(n%2==0) p=n/2-1;
     else p=n/2;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<=p;j++)
         {
             int t=arr[i][j];
             arr[i][j]=arr[i][n-j-1];
             arr[i][n-j-1]=t;
         }
     }
     for(int i=0;i<n-1;i++)
     {
         int k=n-1;
         for(int j=0;j<=n-i-2;j++)
         {
             int t=arr[i][j];
             arr[i][j]=arr[k][n-i-1];
             arr[k][n-i-1]=t;
             k--;
         }
     }
    }
};