int dp[101][2];
int solve(int current_ind, int last_taken, vector<int> nums, int n)
{
    if(current_ind == n)
    return 0;
    if(dp[current_ind][last_taken] != -1)
    return dp[current_ind][last_taken];
    int ans1 = solve(current_ind+1,0,nums,n); // do not take and move forward
    int ans2 = 0;
    if(last_taken == 0)
    ans2 = nums[current_ind] + solve(current_ind+1,1,nums,n); // take and move forward
    return dp[current_ind][last_taken] = max(ans1,ans2);
}
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        /*
        there are 2 possibilities
        1) remove first and include last house - solve(1,0,nums,n)
        2) remove last and include first house - solve(0,0,nums,n-1)
        */
        int n = nums.size();
        if(n==1)
        return nums[0];

        // initialise the DP array
        for(int i=0;i<n;i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        int ans1 = solve(1,0,nums,n); // leave first

        // re-initialise the DP array
        for(int i=0;i<n;i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        int ans2 = solve(0,0,nums,n-1); // leave last
        return max(ans1,ans2);
    }
};
