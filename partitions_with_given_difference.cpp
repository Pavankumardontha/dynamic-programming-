// Recursive DP try converting it into space optimised DP
int dp[51][305];
int solve(int i, int current_sum, int& total_sum, int& d, vector<int>& arr, int& n)
{
    int remaining_sum = total_sum - current_sum;
    int difference = current_sum - remaining_sum;
    if(i==n)
    {
        int remaning_sum = total_sum - current_sum;
        if(current_sum - remaning_sum == d)
        return 1;
        return 0;
    }
    if(dp[i][current_sum] != -1)
    return dp[i][current_sum];
    int ans1 = 0;
    int ans2 = 0;
    // take and not take case
    if(difference<=d)
    {
        // we need to take the current element
        ans1 = solve(i+1,current_sum+arr[i],total_sum,d,arr,n);
    }
    ans2 = solve(i+1,current_sum,total_sum,d,arr,n);
    return dp[i][current_sum] = ans1+ans2;
    
}

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) 
    {
        int n = arr.size();
        int total_sum = 0;
        for(int i=0;i<n;i++)
        total_sum += arr[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=total_sum;j++)
            dp[i][j]=-1;
        }
        return solve(0,0,total_sum,d,arr,n);
        
    }
};
