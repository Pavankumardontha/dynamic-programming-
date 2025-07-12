// order of solutions 1) Recursive DP -> 2) Tabulation -> 3) Space optimisation !!

// Recursive DP solution
int dp[1001][1001];
int solve(int i, int j, string& s1, string& s2, int &n1, int &n2)
{
    if(i==n1 or j==n2)
    return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
    int ans = 0;
    if(s1[i]==s2[j])
    {
        ans = max(ans, 1 + solve(i+1,j+1,s1,s2,n1,n2));
    }
    else
    {
        ans = max(ans,solve(i+1,j,s1,s2,n1,n2));
        ans = max(ans,solve(i,j+1,s1,s2,n1,n2));
    }
    return dp[i][j] = ans;

}
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            dp[i][j]=-1;
        }
        return solve(0,0,s1,s2,n1,n2);
    }
};

// looking at the recursive DP solution we will convert this into tabulation
int dp[1001][1001]
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++)
        dp[i][n2]=0; // filling the last column
        for(int i=0;i<=n2;i++)
        dp[n1][i]=0; // filling then last row

        // we need to start from the last second element of the last second row
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                dp[i][j] = 1 + dp[i+1][j+1];
                else
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};

/* Can we do space optimisation ?? we can clearly see the dp[i][j] values are dependent on the same row elements
or the next row elements so we can do space optimisation */
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> current_dp(n2+1);
        vector<int> next_dp(n2+1);
        next_dp[n2]=0;
        current_dp[n2]=0;
        for(int i=0;i<=n2;i++)
        next_dp[i]=0;

        // we need to start from the last second element of the last second row
        // notice that dp[i+1][j] = next_dp[j] , dp[i][j+1] = current_dp[j+1]
        /*
        So to take the next of the current depends on the values of first index inside
        the dp array.
        dp[i+1][j] -> refers to the jth column in the next row
        dp[i][j+1] -> refers to the (j+1)th column in the same row
        */
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                current_dp[j] = 1 + next_dp[j+1];
                else
                current_dp[j] = max(next_dp[j],current_dp[j+1]);
            }
            next_dp = current_dp;
        }
        return next_dp[0];
    }
};
