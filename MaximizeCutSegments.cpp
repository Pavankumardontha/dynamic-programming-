int x,y,z;
int dp[10001];
int solve(int len)
{
    if(len==0)
    return 0;
    int ans1=INT_MIN,ans2=INT_MIN,ans3=INT_MIN; // these cannot be initialised with 0's
    if(dp[len]!=-1)
    return dp[len];
    // if cut is x
    if(len - x >= 0)
    ans1 = 1 + solve(len - x);
    if(len - y >= 0)
    ans2 = 1 + solve(len - y);
    if(len - z >= 0)
    ans3 = 1 + solve(len - z);
    return dp[len] = max(ans1,max(ans2,ans3));
}
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int X, int Y, int Z)
    {
        memset(dp,-1,sizeof(dp));
        x = X;
        y = Y;
        z = Z;
        int ans = solve(n);
        if(ans<0)
        return 0;
        return ans;
    }
};
