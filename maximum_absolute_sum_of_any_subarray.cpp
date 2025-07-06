class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        /* Notice that the subarray which forms the solution is either the highest possible positive sum or the least possible negative sum.
        The solution is either of the 2. So we find the highest possible positive sum and the least possible negative sum using
        kadanes algorithm.
        We find the maximum subarray sum and the minimum subarray sum. The maximum absolute sum will be the max of both.
        Approach :Apply Kadane's Algorithm to find Maximum Sum Subarray (i.e maxm_sum) and Minimum Sum Subarray (i.e minm_sum)
        Solution : return max( abs(maxm_sum) , abs(minm_sum ))
        */
        int n = nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        int max_sum = dp[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i] < nums[i]+dp[i-1])
            dp[i]=nums[i]+dp[i-1];
            else
            dp[i]=nums[i];
            max_sum = max(max_sum,dp[i]);
        }
        int min_sum = dp[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i]+dp[i-1])
            dp[i]=nums[i]+dp[i-1];
            else
            dp[i]=nums[i];
            min_sum = min(min_sum,dp[i]);
        }
        return max(abs(max_sum),abs(min_sum));
   }
};
