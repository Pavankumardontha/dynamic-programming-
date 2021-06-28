#include<bits/stdc++.h>
#include<iostream>
using namespace std;


string s1;
string s2;

int dp[100][100];
int solve(int i,int j)
{
    if(i==s1.length() || j==s2.length())
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        if(s1[i]==s2[j])
        return dp[i][j]=1+solve(i+1,j+1);
        else
        return dp[i][j]=max(solve(i,j+1),solve(i+1,j));
    }
    
}

int main()
{
    cin>>s1;
    cin>>s2;
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,0);
    cout<<ans<<endl;
}
