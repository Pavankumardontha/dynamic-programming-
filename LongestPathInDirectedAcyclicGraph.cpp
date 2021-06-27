#include<bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> g[100001];
int dp[100001];
int n,m;
bool vis[100001];
void dfs(int v)
{
    vis[v]=1;
    dp[v]=0;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        /* we will first visit the child before finding the farthest node distance from our 
        current node.*/
        if(!vis[child])
        dfs(child);
        dp[v] = max(dp[v],1+dp[child]);
    }
}

int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    /* from each node,we will calculate the distance of the farthest node. so dp[i] will 
    store the distance of the farthest node reachable from node i.For each node,we will 
    find the child which is having farthest node.This ofcourse will also be the farthest node
    reachable from our current node.*/
    for(int i=1;i<=n;i++)
    vis[i]=false;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    for(int i=1;i<=n;i++)
    ans = max(ans,dp[i]);
    cout<<ans<<endl;
}
