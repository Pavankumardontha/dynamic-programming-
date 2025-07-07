int dp[1001][1001];
int solve(int i, int current_sum,vector<int>& nums, int& n, int& target)
{
    if(current_sum == target)
    return 0;
    else if(current_sum > target or i==n)
    return -3000; // sum random minimum no.
    if(dp[i][current_sum] != -1)
    return dp[i][current_sum];
    // take and not take. find the max length obtained in each case.
    int ans1 = -3000;
    if(current_sum+nums[i]<=target)
    ans1 = 1 + solve(i+1,current_sum+nums[i],nums,n,target);
    int ans2 = solve(i+1,current_sum,nums,n,target);
    return dp[i][current_sum] = max(ans1,ans2);
}

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) 
    {
        // dp[i] = length of longest subsequence to form sum i
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            dp[i][j]=-1;
        }
        int ans = solve(0,0,nums,n,target);
        if(ans<=0)
        return -1;
        return ans;
    }
};
