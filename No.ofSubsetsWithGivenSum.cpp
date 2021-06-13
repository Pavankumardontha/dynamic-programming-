class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    /* We will copy the elements of arr into another array since its 0 based index.
	    dp[i][j] = no. of ways to get sum=j using the first i elements.*/
	    vector<int> a(n+1);
	    for(int i=1;i<=n;i++)
	    a[i] = arr[i-1];
	    sort(a.begin()+1,a.end());
        int dp[n+1][sum+1];
        int m = 1e9 + 7;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                dp[i][j]=1;
                else
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                /* we have 2 choices in hand. Think similar to 0-1 knapsack. 
                1) take the current element-can be take only if j-a[i]>=0 
                2) dont take the current element
                */
                if(j-a[i]>=0)
                {
                    /*In this case we have above mentioned 2 choices.*/
                    dp[i][j] = (dp[i-1][j]%m + dp[i-1][j-a[i]]%m)%m;
                }
                else
                {
                    /* We have only one choice in this case ie not to take.*/\
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
	}
	  
};
