class Solution {
public:
bool bfs(int node,vector<vector<int>>& graph,vector<int> &visited)
{
visited[node]=0;
queue<int>q;
q.push(node);
while(q.size()>0)
{
    int curr_v=q.front();
    q.pop();
    int col=visited[curr_v];
    if(col==0) col=1;
    else col=0;
    for(int child:graph[curr_v])
    {
     if(visited[child]==-1)
     {
         visited[child]=col;
         q.push(child);
     }
     else
     {
         int col1=visited[child];
         if(col!=col1) return false;

         continue;
         
     }
    }
}
return true;
} 
    bool isBipartite(vector<vector<int>>& graph) {
          int n=graph.size();
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                bool result=bfs(i,graph,visited);
                if(result == false) return false;
            }
        }
        return true;
    }
};