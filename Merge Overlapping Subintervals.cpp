class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        int m=v.size();
        for(int i=1;i<m;i++)
        {
            if(v[i][0]<=v[i-1][1])
            {
                v[i][0]=v[i-1][0];
                if(v[i][1]<=v[i-1][1])
                v[i][1]=v[i-1][1];
                v[i-1][0]=-1;
                v[i-1][1]=-1;
            }
        }
        for(int i=0;i<m;i++)
        {
          if(v[i][0]==-1 && v[i][1]==-1) continue;
          else 
          {
              ans.push_back(v[i]);
          }

        }
        return ans;

    }
};