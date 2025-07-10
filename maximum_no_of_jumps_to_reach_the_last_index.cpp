int dp[10001];
bool vis[1001];
int solve(int i, vector<int>& nums, int& n, int& target)
{
    if(i==n-1)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int ans = -10001;
    int k;
    vis[i]=true;
    for(int j=i+1;j<n;j++) // given in the question that 0<=i<j<n
    {
        k = abs(nums[j]-nums[i]);
        if(k<=target and vis[j]==false)
        {
            vis[j]=true;
            ans = max(ans,1+solve(j,nums,n,target));
            vis[j]=false;
        }
    }
    vis[i]=false;
    return dp[i] = ans; // we are assigning the ans to dp after exploring all possible options 
}

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            vis[i]=false;
            dp[i]=-1;
        }
        int ans = solve(0,nums,n,target);
        if(ans<=0)
        return -1;
        return ans;
    }
};
