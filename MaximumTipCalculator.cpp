#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int n;//no of orders
int x;//maximum no of orders 'a' can take
int y;//maximum no of orders 'b' can take
vector<int> a;//a[i] is the cost that 'a' earns by taking the order i
vector<int> b;//b[i] is the cost that 'b' earns by taking the order i
/*Both recursion and dp are working.We will try to turn this into dp[].since we
have 3 indices varying with time we will use 3D DP array.*/
int dp[107][107][107];
int solve(int i,int n1,int n2)
{
    if(dp[i][n1][n2]!=-1)
    return dp[i][n1][n2];
    if(i==n)
    return 0;
    else
    {
        /*we can choose either a or b to take the order.*/
        /*a can take the order only if n1>0. b can take the order if n2>0.*/
        int ans1 = 0;
        int ans2 = 0;
        if(n1>0)
        ans1 = a[i] + solve(i+1,n1-1,n2);
        if(n2>0)
        ans2 = b[i] + solve(i+1,n1,n2-1);
        dp[i][n1][n2] = max(ans1,ans2);
        return dp[i][n1][n2];
    }   
}
int main()
 {
	int t;
	cin>>t;
	int k;
	while(t--)
	{
	    a.clear();
	    b.clear();
	    cin>>n;
	    cin>>x;
	    cin>>y;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>k;
	        a.push_back(k);
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>k;
	        b.push_back(k);
	    }
	    memset(dp,-1,sizeof(dp));
	    int ans=solve(0,x,y);
	    cout<<ans<<endl;
	}
	return 0;
}
