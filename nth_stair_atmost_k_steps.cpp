// Number of ways to reach nth stair with at most k steps
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int dp[1001];
int solve(int n1)
{
    if(n1==0)
    return dp[n1]=1;
    int ans = 0;
    if(dp[n1]!=-1)
    return dp[n1];
    for(int i=1;i<=k;i++)
    {
        if((n1-i)>=0)
        ans = ans + solve(n1-i);
        
    }
    return dp[n1]=ans;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<=n;i++)
    dp[i]=-1;
    int ans = solve(n);
    cout<<ans<<endl;
}
