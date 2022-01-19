// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
        int dp[1000001];
        int solve(int n)
        {
            if(dp[n]!=-1)
            return dp[n];
            int ans1 = solve(n/2) + solve(n/3) + solve(n/4);
            if(n>ans1)
            return dp[n]=n;
            else
            return dp[n]=ans1;
        }
        int maxSum(int n)
        {
            dp[0]=0;
            dp[1]=1;
            for(int i=2;i<=n;i++)
            dp[i]=-1;
            int ans = solve(n);
            return ans;
        }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
