int n;
int a[10001];
int dp[10001];
bool solve(int index)
{
    if(index >= n-1)
    {
        // we are on the last index  
        return true;
    }
    if(dp[index]!=-1)
    return dp[index];
    for(int i=1;i<=a[index];i++)
    {
        if(solve(index+i))
        return dp[index] = true;
    }
    return dp[index] = false;
}

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        a[i]=nums[i];
        return solve(0);

    }
};
