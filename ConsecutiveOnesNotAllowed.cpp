class Solution{
public:
	// #define ll long long
	ll countStrings(int n) 
	{
	    /*
	    dp0[i] = no. of binary strings of length i having 0 at the end 
	    dp1[i] = no. of binary strings of length i having 1 at the end
	    */
	    long long int m = 1e9 + 7;
	    long long int dp0[n+1]; 
	    long long int dp1[n+1];
	    dp0[0]=0;
	    dp1[0]=0;
	    dp0[1]=1;
	    dp1[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        dp0[i] = (dp1[i-1]%m + dp0[i-1]%m)%m;
	        dp1[i] = (dp0[i-1])%m;
	    }
	    long long int ans = (dp0[n]%m + dp1[n]%m)%m;
	    return ans;
	}
};
