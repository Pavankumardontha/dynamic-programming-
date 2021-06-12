
/* Lets say we want to jump to N=3 , then 1+2 and 2+1 are considered different and hence both the combinations are counted diffrently. */
class Solution
{
    public:
    int countWays(int n)
    {
        int m = 1e9 + 7;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        dp[i] = (dp[i-1]%m + dp[i-2]%m)%m;
        return dp[n];
    }
};
