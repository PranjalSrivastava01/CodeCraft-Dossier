// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> a, int X, int Y) {
        // code here
        
        if(a[0][0]==0)return 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(N,vector<int>(M,0));
        q.push({{0,0},0});
        vis[0][0]=1;
        
        int Row[] = {-1,0,1,0};
        int Col[] = {0,1,0,-1};
        
        while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        
        q.pop();
        if(row == X && col == Y)return dist;
        
        for(int i=0;i<4;i++){
            int nRow = row+ Row[i];
            int nCol = col + Col[i];
            
            if(nRow>=0 && nRow < N && nCol>=0 && nCol <M && a[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                vis[nRow][nCol] = 1;
                q.push({{nRow,nCol},dist+1});
            }
        }
        
        }
        
        return -1;
        
    }
};