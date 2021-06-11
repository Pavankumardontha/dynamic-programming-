int dp[105][105];
vector<int> a;
int solve(int i,int j)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        int opt1 = a[i] + min(solve(i+2,j),solve(i+1,j-1));
        int opt2 = a[j] + min(solve(i+1,j-1),solve(i,j-2));
        dp[i][j] = max(opt1,opt2);
        return dp[i][j];
    }
}

int maxCoins(int A[],int n)
{
   a.clear();
   for(int i=0;i<n;i++)
   a.push_back(A[i]);
   memset(dp,-1,sizeof(dp));
   int ans = solve(0,n-1);
   return ans;
}
