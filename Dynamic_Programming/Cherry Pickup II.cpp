class Solution {
  int Prnjl(int i,int j1,int j2, int rows,int cols,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
  {
      if(j1<0 || j1>cols-1 ||j2<0 || j2>cols-1) return -1e6;
      if(i==rows-1)
      {
          if(j1==j2) return grid[i][j1];
          else
          {
              return grid[i][j1]+grid[i][j2];
          }
      }
      if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
      int maxi=-1e6;
      int ans=0;
      int k=0;
      for(int d=-1;d<=1;d++)
      {
          for(int j=-1;j<=1;j++)
      {
          if(j1==j2 ) k=grid[i][j1]+Prnjl(i+1,j1+d,j2+j,rows,cols,grid,dp);
          else
          {
           k=grid[i][j1]+grid[i][j2]+Prnjl(i+1,j1+d,j2+j,rows,cols,grid,dp);
          }
          ans=max(k,ans);
      }
      }
      return dp[i][j1][j2]=ans;
    
  }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return Prnjl(0,0,m-1,n,m,grid,dp);
    }
};class Solution {
  int Prnjl(int i,int j1,int j2, int rows,int cols,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
  {
      if(j1<0 || j1>cols-1 ||j2<0 || j2>cols-1) return -1e6;
      if(i==rows-1)
      {
          if(j1==j2) return grid[i][j1];
          else
          {
              return grid[i][j1]+grid[i][j2];
          }
      }
      if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
      int maxi=-1e6;
      int ans=0;
      int k=0;
      for(int d=-1;d<=1;d++)
      {
          for(int j=-1;j<=1;j++)
      {
          if(j1==j2 ) k=grid[i][j1]+Prnjl(i+1,j1+d,j2+j,rows,cols,grid,dp);
          else
          {
           k=grid[i][j1]+grid[i][j2]+Prnjl(i+1,j1+d,j2+j,rows,cols,grid,dp);
          }
          ans=max(k,ans);
      }
      }
      return dp[i][j1][j2]=ans;
    
  }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return Prnjl(0,0,m-1,n,m,grid,dp);
    }
};