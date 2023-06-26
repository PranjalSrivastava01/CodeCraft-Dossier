class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n=v[0].size();
        int m=v.size();
        map<int,int>row;
        map<int,int>column;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)
                {
                    row[i]++;
                    column[j]++;
                }
            }
        }
          for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row.find(i)!=row.end()) v[i][j]=0;
                if(column.find(j)!=column.end()) v[i][j]=0;
            }
        }
       
    }
};