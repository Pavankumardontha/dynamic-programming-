int maxSubarraySum(int a[], int n)
    {
        int dp[n];
        for(int i=0;i<n;i++)
        dp[i] = a[i];
        //dp[i] = maximum sum subarray from indices [0,i] including a[i]
        //note that it is not subsequence. it is subarray and hence leaving any element is not possible 
        int sum = 0;
        int ans = INT_MIN;
        dp[0] = a[0];
        ans = dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i] = max(dp[i-1]+a[i],a[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
