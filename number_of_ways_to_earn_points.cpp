int dp[100][1001];
int mod = 1e9+7;
int solve(int current_ind, int current_sum, int& target, vector<vector<int>>& types, int& n)
{
    if(current_ind==n)
    {
        if(current_sum == target)
        return 1;
        return 0;
    }
    else if(dp[current_ind][current_sum] != -1)
    return dp[current_ind][current_sum];
    else
    {
        int ans1=0;
        int ans2=0;
        /*
        We can take the current question type (types[current_ind][1] marks each) up to 
        types[current_ind][0] times. For each possible count (1 to max available), we:
        - Check if adding these marks keeps us within the target
        - If yes, recursively calculate the number of ways from the next type
        - Sum all valid possibilities
        */
        int count = types[current_ind][0];
        int i=1;
        while(count>0 and current_sum + i*types[current_ind][1]<=target)
        {
            ans1 = (ans1%mod + solve(current_ind+1,current_sum+ i*types[current_ind][1],target,types,n)%mod)%mod;
            count--;
            i++;
        }
        ans2 = (solve(current_ind+1,current_sum,target,types,n))%mod; // do not take current_int type and move forward
        return dp[current_ind][current_sum] = (ans1%mod + ans2%mod)%mod;
    }
}
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) 
    {
        /* push each mark into an array count no. of times */
        int n = types.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            dp[i][j]=-1;
        }
        return solve(0,0,target,types,n);
    }
};
