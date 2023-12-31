//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(int node, vector<int> adj[],vector<int>&visited,vector<int>&ans)
  {
      queue<int>q;
      q.push(node);
      visited[node]=1;
      while(q.size()>0)
      {
          int curr_v=q.front();
          q.pop();
          ans.push_back(curr_v);
          for(int child:adj[curr_v])
          {
              if(visited[child]==1) continue;
              q.push(child);
              visited[curr_v]=1;
          }
      }
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>visited(V,0);
        bfs(0,adj,visited,ans );
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends