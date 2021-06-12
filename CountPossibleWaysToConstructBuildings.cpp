class Solution
{
	public:
	int TotalWays(int n)
	{
	    /* this is very similar  to consecutive 1's not allowed problem.Consider here 
	    buildings as 1.*/
	    long long int m = 1e9 + 7;
	    long long int dpS[n+1];
	    long long int dpB[n+1];
	    dpS[0]=0;
	    dpB[0]=0;
	    dpS[1]=1;
	    dpB[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        dpS[i] = (dpS[i-1]%m + dpB[i-1]%m)%m;
	        dpB[i] = dpS[i-1];
	    }
	    long long int ans = (dpS[n]%m + dpB[n]%m)%m;
	    /*Total possible ways = ans*ans. This is because a way to place on one side can 
	    correspond to any of 5 ways on other side.*/
	    ans = ((ans%m)*1LL*(ans%m))%m;
	    return ans;
	}
	
};
