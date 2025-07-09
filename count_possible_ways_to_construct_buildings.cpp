long long int mod = 1e9 + 7;
long long int dp[100001][2];
long long int solve(int current_plot,int last_plot_constructed, int n)
{
    if(current_plot==n)
    return 1;
    long long int ans1 = 0;
    long long int ans2 = 0;
    if(dp[current_plot][last_plot_constructed]!=-1)
    return dp[current_plot][last_plot_constructed];
    ans1 = solve(current_plot+1,0,n)%mod; // do not construct and just move on
    if(last_plot_constructed == 0)
    ans2 = solve(current_plot+1,1,n)%mod;
    return dp[current_plot][last_plot_constructed] = (ans1%mod + ans2%mod)%mod;
}

class Solution {
  public:
    int TotalWays(int N) 
    {
        for(int i=0;i<=N;i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        /*Total possible ways = ans*ans. This is because a way to place on one side can 
	    correspond to any of ans no. of ways on other side.*/
        int ans = solve(0,0,N);
        return ((ans%mod)*(ans%mod))%mod;
    }
};
