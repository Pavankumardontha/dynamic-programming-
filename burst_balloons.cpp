/*
Imagine you have ballons [b1,b2,b3,b4,b5]
We need to find the optimal order in which they can be burst so that we can collect maximum coins

Lets say we first burst b3 then need to solve 2 sub problems

coins = b2*b3*b4 + solve([b1,b2]) + solve([b4,b5])
But notice clearly that solve([b1,b2]) is dependent on solve([b4,b5]).
These are not independent subproblems to deal with because ,
Imagine we are solving subproblem solve([b1,b2]). In this case,
when we burst lets say b2, we need to know what element will be present to its right.
The element to the right of b2 depends on how we solve the subproblem solve[b4,b5]. 
The element to the right of b2 can either be one of b4 or b5,

In the above approach , we first bursted one balloon and tried to solve its subproblems.
Instead of this approach , we will come from the back. We will first guess the last balloon 
to be bursted and then the last second and so on..

[b1,b2,b3,b4,b5]

-> 5th burst b3 -> [b3] , since its bursted last , coins = 1*b3*1 = b3
-> 4th burst b4 -> [b3,b4] , coins = 1*b3*b4
-> 3rd burst b5 -> [b3,b4,b5] , coins = b4*b5*1
-> 2nd burst b1 -> [b1,b3,b4,b5] , coins = 1*b1*b3
-> 1st burst b2 -> [b1,b2,b3,b4,b5] coins = b1*b2*b3

-> order of bursting : [b2,b1,b5,b4,b3] , total coins = sum of all coins obtained above

if we have a range of balloons from indices (i,j) and if we burst a ballon at index ind (i<=ind<=j) at the last
then the obtained coins = a[i-1]*a[ind]*a[j+1]
Since its bursted last in the range of balloons from (i,j) , we are multiplying with 
a[i-1] and a[j+1] which will be the left and right elements of a[ind].

if i-1<0 then we multiply by 1 (since there is no left element to a[ind] -> first balloon)
if j+1>=n then we multiply by 1 (since there is no right element to a[ind] -> last balloon)

so lets take array:[b1,b2,b3,b4,b5]
lets say we burst b3 at the last then
solve([b1,..b5]) = 1*b3*1 + solve([b1,b2]) + solve([b4,b5])
now think whether the sub-problems solve([b1,b2]) and solve([b4,b5]) are independent or not.
-> yes they are independent and can be solved seperately because we now know for sure that b3 will burst at the end
so it will be to the right of [b1,b2] till the subproblem solve([b1,b2]) is solved.
In a similar way b3 will be to the left of [b4,b5] till subproblem solve([b3,b4]) is solved.
This makes sure the right and left elements are fixed before we solve for a range of balloons
(i,j) which was not true in the first approach
*/

int dp[301][301];
int solve(int i, int j, vector<int>& nums, int n)
{
    int left,right;
    if(i-1<0)
    left = 1;
    else
    left = nums[i-1];
    if(j+1>=n)
    right=1;
    else
    right = nums[j+1];
    if(i==j)
    return dp[i][j] = left*nums[i]*right;
    else if(i>j)
    return 0;
    else if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        int ans=INT_MIN;
        int temp_ans;
        for(int ind=i;ind<=j;ind++)
        {
            temp_ans = left*nums[ind]*right + solve(i,ind-1,nums,n) + solve(ind+1,j,nums,n);
            ans = max(ans,temp_ans);
        }
        return dp[i][j] = ans;
    }
}
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=n-1;
        memset(dp,-1,sizeof(dp));
        return solve(i,j,nums,n);
    }
};
