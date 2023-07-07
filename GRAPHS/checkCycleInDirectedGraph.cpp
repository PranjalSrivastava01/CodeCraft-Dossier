class Solution {
public:
    bool dfs(int node, vector<vector<int>>& g, vector<int>& visited, vector<int>& isDfs) {
        visited[node] = 1;
        isDfs[node] = 1;
        
        cout<<node<<endl;
        // if (g[node].empty()) return false;
        
        for (int child : g[node]) {
            if (visited[child] == 1) {
                if (isDfs[child] == 1) return true;
                else continue;
            }
            
            bool isCycl = dfs(child, g, visited, isDfs);
            isDfs[child] = 0;
            if (isCycl) return true;
        }
        isDfs[node] = 0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        for (int i = 0; i < pre.size(); i++) {
            int x = pre[i][0];
            int y = pre[i][1];
            g[x].push_back(y);
        }
        
        vector<int> visited(n, 0);
        vector<int> isDfs(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] != 1) {
                bool isCycle = dfs(i, g, visited, isDfs);
                if (isCycle) 
                {
                //  cout<<i<<isDfs[0];
                 return false;
                }
                
            }
        }
        
        return true;
    }
};