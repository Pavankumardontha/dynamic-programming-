// dp[i] = no. of ways to get sum i using any values present in coins array

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	int n,sum;
	cin>>n>>sum;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> dp(sum+1,0);
	int mod = 1e9+7;
	// dp[i] = no. of ways to get sum i using any values present in coins array
	/* To reach the given state i, we can reach it either by taking coins[0] or coins[1].. or coins[n-1] in the previous step.
	So dp[i] = dp[i-coins[0]] + dp[i-coins[1]] + ...+ dp[i-coins[n-1]
	dp[i] depends on n states or n subproblems
	*/
	dp[0]=1;
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i-a[j]>=0)
				dp[i] = (dp[i]%mod + dp[i-a[j]]%mod)%mod;
		}
	}
	cout<<dp[sum]<<endl;
}
