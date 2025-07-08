/*
Space optimization in DP:
Think of these 2 points 
Q1) What other states does our current state depend on ? In fibonaci , dp[n] = dp[n-1] + dp[n-2] So the current state depends only on the 
previous two states and not beyond those. So instead of storing solutions for all the states in the DP array, we can only store previous
two solutions and arrive at the solution. This is possible in iterative approach. Similarly in the dice combinations problem, the current
state is depended on the previous 6 states. So we can store only the last 6 values and discard all of other states.

Now consider an example 
dp[i][j] = min(dp[i-1][j],dp[i][j-1])
Imagine a point in the 2D grid (i,j) for which we want to compute the solution. This state depends on the cell above it and the cell to 
the left of it. So to solve for the entire cells in the current row, we only need solutions of the previous row and the current row.

Imagine a 2D grid as given below
. . . . . .
A B C D E F
I J K L M N
. . . . . .
. . . . . .
so to solve state L, we need state D and state K solution. Similarly to solve the entire row starting from I , we need all the solutions in the
previous row and the current row. 
So instead of storing N*M state solutions we will only store M state solutions of the previous state.

Q2) Do we need the answers of every single state to calculate the answer for our current state ?? 
*/

/*
Lets now come to our current DP problem.
dp[i][current_sum] depends on dp[i][current_sum-coins[i]](taking coins[i]) and dp[i+1][current_sum](not taking coins[i])
dp[i][current_sum-coins[i]] belongs to the same row to the left of our current state.
dp[i+1][current_sum] belongs to the next row. 
So to solve the given state, we need the solutions to the states in the next row and to the states in the current row to the left of our state.
So instead of storing O(N*M) we can store O(2*M) which is O(M) where M is the no. of columns which in our case is O(SUM)
*/

// NOTE :- Write the recursive solution , then get into optimisation using the recurence relation.
// iterative DP solution. Note that this is 1D and NOT 2D !!
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        // only combinations
        int n = coins.size();
        vector<unsigned long long int> current_row_dp(amount+1,0); // solutions to states in current row
        vector<unsigned long long int> next_row_dp(amount+1,0); // solutions to states in next row
        // we need to solve this from the last row since the current state depends on the next row.
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=amount;j++)
            {
                // using the coins present in the range [i,n-1] form a sum j
                if(j==0)
                {
                    current_row_dp[j]=1;
                }
                else if(i==n-1)
                {
                    if(j-coins[i]>=0)
                    current_row_dp[j] += current_row_dp[j-coins[i]];
                }
                else
                {
                    if(j-coins[i]>=0)
                    current_row_dp[j] += current_row_dp[j-coins[i]]; // take
                    current_row_dp[j] += next_row_dp[j]; // not take
                }
            }
            // populate the next and current state dp
            for(int j=0;j<=amount;j++)
            {
                next_row_dp[j] = current_row_dp[j];
                current_row_dp[j] = 0;
            }
        }
        return next_row_dp[amount];
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
