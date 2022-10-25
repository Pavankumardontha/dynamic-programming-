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
