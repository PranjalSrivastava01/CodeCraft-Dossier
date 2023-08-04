//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int N1=1e5+10;
  int INF=1e9+10;
  void dijkistra(vector<pair<int,int>> g[],vector<int> &dis,vector<int> &vis,int source)
  {
     set<pair<int,int>>s;
     s.insert({0,source});
     dis[source]=0;
     while(s.size()>0)
     {
         auto curr_node=*s.begin();
         int curr_v=curr_node.second;
         int dis_v=curr_node.first;
         s.erase(s.begin());
         if(vis[curr_v]==1) continue;
         vis[curr_v]=1;
         for(auto child:g[curr_v])
         {
             int wt=child.second;
             if(dis[child.first]>dis_v+wt)
             {
                 dis[child.first]=dis_v+wt;
                 s.insert({dis[child.first],child.first});
             }
         }
     }
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       vector<pair<int,int>>g[N];
       for(auto child:edges)
       {
           g[child[0]].push_back({child[1],child[2]});//---->1->2,weight
       }
       vector<int>vis(N,0);
       vector<int>dis(N,INF);
       dijkistra(g,dis,vis,0);
       for(int i=0;i<dis.size();i++)
       {
           if(dis[i]==INF) dis[i]=-1;
       }
       return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends