class Solution {
public:
    int Prnjl(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0 || j>n-1) return 1e6;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=matrix[i][j]+Prnjl(i-1,j,n,matrix,dp);
        int leftd=matrix[i][j]+Prnjl(i-1,j-1,n,matrix,dp);
        int rightd=matrix[i][j]+Prnjl(i-1,j+1,n,matrix,dp);
        return dp[i][j] = min(up, min(leftd, rightd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int mini = 1e6;
    for(int i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int up = matrix[i][j] + dp[i-1][j];
            int leftd = matrix[i][j];
            if(j - 1 >= 0) leftd += dp[i-1][j-1];
            else leftd=1e6;
            int rightd = matrix[i][j];
            if(j + 1 < n) rightd += dp[i-1][j+1];
            else rightd=1e6;
            dp[i][j] = min(up, min(leftd, rightd));
        }
    }
    for(int i = 0; i < n; i++) {
        int k = dp[n-1][i];
        mini = min(mini, k);
    }
    return mini;
}
};

