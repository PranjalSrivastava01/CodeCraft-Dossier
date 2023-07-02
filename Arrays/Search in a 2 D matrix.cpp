#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        vector<int>ans;
        int m=v.size();
        int n=v[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans.push_back(v[i][j]);
            }
        }
         if (binary_search(ans.begin(), ans.end(), target))
         {
             return true;
         }
         return false;

    }
};