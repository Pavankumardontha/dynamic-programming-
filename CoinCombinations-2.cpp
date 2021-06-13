#include <iostream>
#include <algorithm>
using namespace std;
 
int dp[1000005], mod=1e9+7, coins[105];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin>>n>>x;
    for (int i=0;i<n;i++)
    cin>>coins[i];
    dp[0]=1;
    /* In coin combination-1, we will the outer loop running from 1 to sum. In coin combination-2 we have the inner loop running from 1 to sum. Rest everything is same.
	     If we want to make a sum using coins(each coin is of infinite supply) , we have 2 possibilities 
	     a) Permutations matter(outer loop on sum).
	     b) Only combinations matter(inner loop on sum)
	     We are now solving case-b
	*/
    for (int i=0;i<n;i++)
    {
        for (int j=1;j<=x;j++)
        {
            if (j-coins[i]>=0)
            dp[j]=(dp[j]%mod+dp[j-coins[i]]%mod)%mod;
        }
    }
    cout<<dp[x]%mod<<endl;
    return 0;
}
