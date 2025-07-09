int dp[101];
int solve(vector<int> &nums , int current_index)
{
    if(current_index>=nums.size())
        return 0;
    /*
    At any given point of time , we can either 
    a) take the current index and move 2 steps forward 
    b) Do not take the current index number and just move 1 step forward
    */
    if(dp[current_index]!=-1)
        return dp[current_index];
    int ans1 = nums[current_index] + solve(nums,current_index+2);
    int ans2 = solve(nums,current_index+1);
    return dp[current_index] = max(ans1,ans2);
}

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0);
        return ans;
        
    }
};
