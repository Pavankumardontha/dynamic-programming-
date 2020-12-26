class Solution
{

	public:
	int minCoins(int a[], int n, int sum) 
	{ 
	   /*You have coins and you have to make a value V with these coins by using 
	   the minimum no. of coins.*/
	   int dp[sum+1];
	   
	   dp[0]=0;
	   for(int i=1;i<=sum;i++)
	   dp[i]=INT_MAX;
	   
	   sort(a,a+n);
	   
	   
	   for(int j=1;j<=sum;j++)
	   {
	       for(int i=0;i<n;i++)
	       {
	           if(j-a[i]>=0)
	           {
	               if(dp[j-a[i]]!=INT_MAX)
	               dp[j]=min(dp[j],1+dp[j-a[i]]);
	           }
	       }
	   }
	   
	   if(dp[sum]==INT_MAX)
	   return -1;
	   else
	   return dp[sum];
	} 
	  
};
