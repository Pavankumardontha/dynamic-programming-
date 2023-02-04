int a[10001];
int dp[10001];
int n;

int solve(int index)
{
    if(index>=n-1)
    return 0;
    if(dp[index]!=1e8)
    return dp[index];
    /* From 0 index you can take a jump and reach all indexes upto a[0].From any i index you can take a jump and reach all indexes in range of a[i]
    so to reach n-1 from index i , we only have a[i] ways and we need to search for minimum steps in each of these ways.*/
    for(int i=1;i<=a[index];i++)
    dp[index] = min(dp[index],1+solve(index+i));
    return dp[index];
}

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        /* not use memset to initialize arrays other than -1 and false */
        n = nums.size();
        for(int i=0;i<n;i++)
        {
            a[i]=nums[i];
            dp[i]=1e8;
        }
        for(int i=0;i<n;i++)
        cout<<dp[i]<<endl;
        return solve(0);
    }
};
