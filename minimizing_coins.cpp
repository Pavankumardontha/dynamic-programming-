#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	int n,sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector<long long int> dp(sum+1,INT_MAX); // initialising with some large value
	// dp[i] = minimum coins required to construct sum i = subproblem = state
	/*
	We can reach to the subproblem i by taking any of the element present in coins array. 
	But out of all these choices, we need to choose the one that gives minimum coins to 
	produce the sum i. So 
	dp[i] = 1 + min(dp[i-a[0]],dp[i-a[1]],dp[i-a[2]]......)
	*/
	dp[0]=0;
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i-a[j]>=0)
			dp[i] = min(dp[i],1 + dp[i-a[j]]);
		}
	}
	if(dp[sum]==INT_MAX)
	cout<<-1<<endl;
	else
	cout<<dp[sum]<<endl;	
}
