#include<bits/stdc++.h>
int dp[1000001][2];
int solve(int i,int skiped,int A[], int n)
{
    if(i==n)
    return 0;
    if(dp[i][skiped] != -1)
    return dp[i][skiped];
    int ans1=INT_MAX;
    int ans2=INT_MAX;
    if(skiped == 0) // since the last task is not skipped we can skip the current task
    ans1 = solve(i+1,1,A,n);
    ans2 = A[i] + solve(i+1,0,A,n);
    return dp[i][skiped] = min(ans1,ans2);
}

class Solution {
  public:
    int minAmount(int A[], int N) 
    {
        // 1 means skipped is true and 0 means false
        for(int i=0;i<N;i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        return solve(0,0,A,N);
    }
};
    
