long long int dp[1005][1005];
vector<int> a;
long long solve(int i,int j)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        long long int opt1 = a[i] + min(solve(i+2,j),solve(i+1,j-1));
        long long int opt2 = a[j] + min(solve(i+1,j-1),solve(i,j-2));
        dp[i][j] = max(opt1,opt2);
        return dp[i][j];
    }
}
long long maximumAmount(int arr[], int n) 
{
    /* Lets say we have A[i],A[i+1],A[i+2]..........A[j-2],A[j-1],A[j]. Its clear that 
    since the opponent is also clever, he will try to minimize the options we get. 
    We can take either A[i] or A[j]. 
    1)If we take A[i],the opponent may take either A[i+1] or A[j].
    2)If we take A[j],the opponent may take either A[i] or A[j-1].
    solution-1 = A[i] + min(solve(A[i+1],A[j]))
    solution-2 = A[j] + min(solve(A[i],A[j-1]))
    solution = max(solution-1,solution-2)
    dp[i][j] = max(solution-1,solution-2)
    */
    a.clear();
    for(int i=0;i<n;i++)
    a.push_back(arr[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        dp[i][j]=-1;
    }
    long long int ans = solve(0,n-1);
    return ans;
}
