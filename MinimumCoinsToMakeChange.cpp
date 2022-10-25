long long int dp[10001];
int n;
int coins[10001];
long long int solve(int value)
{
    if(value == 0)
    return 0;
    
    /* At any given point of time we can take any coin if our current_valu - coin value is greater than or equal to 0. */
    if(dp[value]!=-1)
    return dp[value];
    long long int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(value-coins[i] >= 0)
        {
            long long int temp = 1 + solve(value-coins[i]);
            if(temp < ans)
            ans = temp;
        }
    }
    return dp[value] = ans;
}

class Solution{

	public:
	int minCoins(int c[], int M, int V) 
	{ 
	    n = M;
	    sort(c,c+n);
	    for(int i=0;i<n;i++)
	    coins[i]=c[i];
	    memset(dp,-1,sizeof(dp));
	    int ans = solve(V);
	    if(ans == INT_MAX)
	    return -1;
	    return ans;
	} 
	  
};
