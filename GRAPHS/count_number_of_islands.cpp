class Solution {
    //no need to createv visited array
public:
 void dfs(int i,int j,vector<vector<char>>& grid)
 {
    int m=grid.size();
    int n=grid[0].size();
     if(i<0 || j<0) return;
     if(i>=m || j>=n) return;
     if(grid[i][j]!='1') return;
     grid[i][j]='2';
     dfs(i-1,j,grid);
     dfs(i+1,j,grid);
     dfs(i,j-1,grid);
     dfs(i,j+1,grid);
} 
    
 
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
    
        return cnt;
    }
};