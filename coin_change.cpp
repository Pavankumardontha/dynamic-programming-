class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        // dp[i] = minimum coins required to construct sum i = subproblem = state
	      /* We can reach to the subproblem i by taking any of the element present in coins array. But out of all these choices, we need to choose the one that gives minimum coins to 
	        produce the sum i. So dp[i] = 1 + min(dp[i-a[0]],dp[i-a[1]],dp[i-a[2]]......) */
        int n = coins.size();
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-coins[j]>=0)
                dp[i]=min(dp[i],1+dp[i-coins[j]]);   
            }
        }
        if(dp[amount]==INT_MAX-1)
        return -1;
        return dp[amount];
    }
};
