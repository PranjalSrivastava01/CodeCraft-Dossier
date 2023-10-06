bool Prnjl(int i, int target, vector<int>& a, vector<vector<int>>& dp) {
    if(target == 0) return dp[i][target] = true;
    if(i == 0) return dp[i][target] = (a[0] == target);
    if(dp[i][target] != -1) return dp[i][target];
    bool npic = Prnjl(i - 1, target, a, dp);
    bool pic = a[i] <= target ? Prnjl(i - 1, target - a[i], a, dp) : false;
    return dp[i][target] = pic || npic;
}

int minSubsetSumDifference(vector<int>& nums, int n)
{
    int s = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(n, vector<int>(s+1, -1));

    for (int i = 0; i < n; i++) {
        Prnjl(i, 0, nums, dp);
    }

    int mini = INT_MAX;
    for (int i = 0; i <= s; i++) {
        if (dp[n - 1][i]) {
            int diff = abs(i - (s - i));
            mini = min(mini, diff);
        }
    }

    return mini;
}
