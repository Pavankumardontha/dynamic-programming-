class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        /*
        Approach :Apply Kadane's Algorithm to find Maximum Sum Subarray (i.e maxm_sum) and Minimum Sum Subarray (i.e minm_sum)
        Solution : return max( abs(maxm_sum) , abs(minm_sum ))
        */
        int n = nums.size();
        int dp[n];
        int max_ans = nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
            max_ans = max(max_ans,dp[i]);
        }
        int min_ans=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i] = min(dp[i-1]+nums[i],nums[i]);
            min_ans = min(min_ans,dp[i]);
        }
        return max(abs(max_ans),abs(min_ans));
    }
};
