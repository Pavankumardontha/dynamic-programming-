int n,sum;
vector<int> a;
int dp[10001];
int solve(int current_sum)
{
    if(current_sum==sum)
        return 1;
    if(current_sum > sum)
        return 0;
    if(dp[current_sum] != -1)
        return dp[current_sum];
    int ans = 0;
    for(int i=0;i<a.size();i++)
        ans = ans + solve(current_sum + a[i]);
    return dp[current_sum] = ans;
}

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        sum = target;
        a.clear();
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            a.push_back(nums[i]);
        return solve(0);
    }
};
