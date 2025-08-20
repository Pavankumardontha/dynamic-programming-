
int dp[100001][3];
int mod=1e9+7;
int solve(int i, int count, string& s, int& n)
{
    if(i==n)
    {
        if(count == 2)
        {
            /*
            we are able to get 2 seats from the previous room divider to the last divider so this is a valid
            way of dividing the seats properly */
            return 1;
        }
        else
        {
            // this is in valid way since we do have 2 seats from previous to last divider
            return 0;
        }
    }
    else if(dp[i][count]!=-1)
    return dp[i][count];
    else
    {
        // from our current position we can do 2 things
        // either just move ahead without putting any room divider
        // put the room divider
        int ans1 = 0;
        int ans2 = 0;
        int ans = 0;
        if(count<2)
        {
            if(s[i]=='P')
            {
                // just move forward
                ans1 = (solve(i+1,count,s,n))%mod;
            }
            else
            {
                // this means we have a seat here
                ans1 = (solve(i+1,count+1,s,n))%mod;
            }
        }
        else
        {
            // count = 2 here
            if(s[i]=='P')
            {
                // we can keep a break here and move forward or just move forward
                ans1 = (solve(i+1,count,s,n))%mod;
                ans2 = (solve(i+1,0,s,n))%mod;   
            }
            else
            {
                // we have to keep a break
                ans1 = (solve(i+1,1,s,n))%mod;
            }
        }
        return dp[i][count] = ((ans1)%mod + (ans2)%mod)%mod;
    }
}

class Solution {
public:
    int numberOfWays(string corridor) 
    {
        string s = corridor;
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,n);
    }
};
