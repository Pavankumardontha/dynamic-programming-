// recursive DP
int dp[1001][1001];
int solve(int current_ind, int current_sum, vector<int>& arr, int& target, int& n)
{
    
    if(current_ind==n)
    {
        /*
        this is very important since we have 0's as well
        we cannot have the below if condition at the start
        if(current_sum == target) 
        return 1;
        */
        if(current_sum == target)
        return 1;
        return 0;
    }
    if(current_sum > target)
    return 0;
    if(dp[current_ind][current_sum] != -1)
    return dp[current_ind][current_sum];
    // take and move forward
    int ans1 = solve(current_ind+1,current_sum+arr[current_ind],arr,target,n);
    // do not take and move forward
    int ans2 = solve(current_ind+1,current_sum,arr,target,n);
    return dp[current_ind][current_sum] = ans1+ans2;
}
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) 
    {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            dp[i][j]=-1;
        }
	// dp[i][j] = in how many ways we can obtain sum=target from current_sum=y taking elements in the range [i,n-1]
        return solve(0,0,arr,target,n);
    }
};

/*
From above we can notice that :
dp[current_ind][current_sum] = dp[current_ind+1][current_sum] (dont take) + dp[current_ind+1][curren_sum+arr[current_ind]] (take)
This means: To compute dp[i][sum], we only need values from dp[i+1][*] — i.e., the next row. So we can use two 1D arrays: curr and next.
Space complexity : O(target) used to store the next state.
*/













