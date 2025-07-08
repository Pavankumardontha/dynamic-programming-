// iterative DP solution. Note that this is 1D and NOT 2D !!
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        // only combinations
        int n = coins.size();
        vector<unsigned long long int> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j-coins[i] >= 0)
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};


// Recursive DP solution - Note that this is 2D DP
// dp[i][sum] = no. of combinatations possible to make sum by taking elements in the range [i,n]
/* At any given state, we cannot take any coin from the coins array. We need to take the coins from the right to produce distinct combinations. If order does matter , we can 
take any coin from the coins array at any given point of time. But here we need to make sure the order does not matter(all the permutations are considered same). So to eliminate
the permutations, we make sure at any current state (current_ind,current_amount) , we only pick elements in the range [current_ind,n] and not from the range [0,current_ind-1]
since these produce the same permutations again. Due to this, our recursive DP solution becomes 2D. */
int n;
int target;
int dp[301][5001];
int solve(int current_ind, int current_sum, vector<int>& coins)
{
    if(current_sum == target)
    return 1;
    else if(current_sum > target or current_ind == n)
    return 0;
    if(dp[current_ind][current_sum]!=-1)
    return dp[current_ind][current_sum];
    // we need to now explore all the possibilities
    // take the current element and do not take the current element
    int ans1 = 0;
    int ans2 = 0;
    if(current_sum + coins[current_ind] <= target)
    ans1 = solve(current_ind,current_sum + coins[current_ind],coins);
    ans2 = solve(current_ind+1,current_sum,coins);
    return dp[current_ind][current_sum] = ans1+ans2;
}
