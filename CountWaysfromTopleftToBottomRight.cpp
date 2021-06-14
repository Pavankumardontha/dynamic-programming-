class Solution {
  public:
    long long int numberOfPaths(int m, int n)
    {
        long long dp[m+1][n+1];
        for(int i=1;i<=m;i++)
        dp[i][1] = 1;
        for(int i=1;i<=n;i++)
        dp[1][i] = 1;
        long long int m1 = 1e9 + 7;
        for(int i=2;i<=m;i++)
        {
            for(int j=2;j<=n;j++)
            {
                dp[i][j] = ((dp[i-1][j])%m1 + (dp[i][j-1])%m1)%m1;
            }
        }
        return dp[m][n];
    }
    
};
