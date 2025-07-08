#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int dp[n+1]={0};
	// dp[i] = no. of to construct sum i by throwing a dice one or more times = subproblem = state
	/* We can reach to the subproblem i by having the previous dice value of 1 or 2....or 6
	   so dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6] */
	int mod = 1e9+7;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=6;j++)
		{
			if(i-j>=0)
			dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
		}
	}
	cout<<dp[n]<<endl;	
}

/*-----------------------------------------------------------------*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// MODEL :- Repetition in taking of elements allowed + Combinations 
int dp[1000001], mod=1e9+7,sum;
int solve(int current_sum)
{
    if(current_sum == sum)
    return 1;
    if(current_sum > sum)
    return 0;
    if(dp[current_sum]!=-1)
    return dp[current_sum];
    int ans = 0;
    for(int j=1;j<=6;j++)
    ans = (ans%mod + solve(current_sum + j)%mod)%mod;
    return dp[current_sum] = ans%mod;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>sum;
    memset(dp,-1,sizeof(dp));
    int ans = solve(0);
    cout<<ans%mod<<endl;
	return 0;
}
